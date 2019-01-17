#include "../includes/ft_ls_lib.h"
#include "../queue/ft_queue_lib.h"
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

void	ft_test_l(const char *path)
{
		//Defining the different components of the program
        //The directory: it's the folder we're browsing (we'll use an argument (argv) in order to identify it)
    DIR *dir;
        //The file: when a file is found in the directory readdir loop, it's going to be called this way.
    struct dirent *dptr;
        //The stat: It's how we'll retrieve the stats associated to the file. 
    struct stat thestat;
        //will be used to determine the file owner & group
    struct passwd *tf; 
    struct group *gf;

    //Creating a placeholder for the string. 
    //We create this so later it can be properly adressed.
    //It's reasonnable here to consider a 512 maximum lenght, as we're just going to use it to display a path to a file, 
    //but we could have used a strlen/malloc combo and declared a simple buf[] at this moment
    char buf[512];

    //It's time to assign thedirectory to the argument: this way the user will be able to browse any folder simply by mentionning it 
    //when launching the lsd program.
    dir = opendir(path);

    //If a file is found (readdir returns a NOT NULL value), the loop starts/keep going until it has listed all of them. 
    while((dptr = readdir(dir)) != NULL) 
    {   
        //We sprint "thedirectory/thefile" which defines the path to our file 
        sprintf(buf, "%s/%s", path, dptr->d_name);
        //Then we use stat function in order to retrieve information about the file
        stat(buf, &thestat);

        //Now, we can print a few things !
        // Here's the right order
        // [file type] [permissions] [number of hard links] [owner] [group] [size in bytes] [time of last modification] [filename]

        // [file type]
        //Let's start with the file type
        //The stat manual is pretty complete and gives details about st_mode and S_IFMT: http://manpagesfr.free.fr/man/man2/stat.2.html
        //
        switch (thestat.st_mode & S_IFMT) {
            case S_IFBLK:  printf("b "); break;
            case S_IFCHR:  printf("c "); break; 
            case S_IFDIR:  printf("d "); break; //It's a (sub)directory 
            case S_IFIFO:  printf("p "); break; //fifo
            case S_IFLNK:  printf("l "); break; //Sym link
            case S_IFSOCK: printf("s "); break;
            //Filetype isn't identified
            default:       printf("- "); break;
                }
        //[permissions]
        //Same for the permissions, we have to test the different rights
        //READ http://linux.die.net/man/2/chmod 
        printf( (thestat.st_mode & S_IRUSR) ? " r" : " -");
        printf( (thestat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (thestat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (thestat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (thestat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (thestat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (thestat.st_mode & S_IROTH) ? "r" : "-");
        printf( (thestat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (thestat.st_mode & S_IXOTH) ? "x" : "-");

        // [number of hard links] 
        // Quoting: http://www.gnu.org/software/libc/manual/html_node/Attribute-Meanings.html
        // "This count keeps track of how many directories have entries for this file. 
        // If the count is ever decremented to zero, then the file itself is discarded as soon as no process still holds it open."
        printf("\t%d ", thestat.st_nlink);

        //[owner] 
        // http://linux.die.net/man/3/getpwuid
        tf = getpwuid(thestat.st_uid);
        printf("\t%s ", tf->pw_name);

        //[group]
        // http://linux.die.net/man/3/getgrgid
        gf = getgrgid(thestat.st_gid);
        printf("\t%s ", gf->gr_name);

        //And the easy-cheesy part
        //[size in bytes] [time of last modification] [filename]
        printf("%zu",thestat.st_size);
        printf(" %s", dptr->d_name);
        printf(" %s", ctime(&thestat.st_mtime));
    }
    closedir(dir);
}

int main(int argc, char *argv[])
{
	ft_test_l(argv[1]);

	//ft_test_queue();
	return (0);
}
