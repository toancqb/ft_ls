
FLAGS=

SRC=src/*.c
INC=includes/*.h
OBJ=src/*.o
PROJET_NAME=ft_ls
LIB=libft/libft.a

all:
	gcc $(FLAGS) $(SRC) $(LIB) -o $(PROJET_NAME)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(PROJET_NAME)
re:	fclean	all	
