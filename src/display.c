/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:14:20 by qtran             #+#    #+#             */
/*   Updated: 2018/12/18 20:14:23 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls_lib.h"

void	queue_display(t_queue *qt)
 {
   if (qt)
   {
     while (qt != NULL)
     {
       ft_putstr(qt->content); ft_putstr("  ");
       qt = qt->next;
     }
     ft_putchar('\n');
   }
 }

void  ft_longformat(const char *path)
{
  int i;
  char *c;
    struct passwd *pw;
    struct group *gp;
    struct stat fileStat;

    stat(path,&fileStat);  
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-"); 
    printf(" ");
    printf("%d ",fileStat.st_nlink);
    pw=getpwuid(fileStat.st_uid);
    printf("%s ",pw->pw_name);
    gp=getgrgid(fileStat.st_gid);
    printf("%s ",gp->gr_name);
    printf("%4d ",fileStat.st_size);
    c=ctime(&fileStat.st_mtime);
    for(i=4;i<=15;i++)
      printf("%c",c[i]);
    printf(" ");
    printf("%s\n",path);
}