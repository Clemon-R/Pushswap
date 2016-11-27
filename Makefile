##
## Makefile for 101pong in /home/raphael.goulmot/rendu/101pong
## 
## Made by Raphaël Goulmot
## Login   <raphael.goulmot@epitech.net>
## 
## Started on  Mon Nov  7 16:40:32 2016 Raphaël Goulmot
## Last update Sun Nov 27 17:41:18 2016 Raphaël Goulmot
##

SRC	=	src/core/main.c		\
		src/core/pushswap.c	\
		src/utils/my_getnbr.c	\
		src/utils/my_put_nbr.c	\
		src/utils/my_putchar.c	\
		src/utils/my_putstr.c

OBJ	=	$(SRC:.c=.o)

TMP	=	$(SRC:.c=.c~)

CFLAGS	=	-Wextra -Wall -Werror -Iinclude

NAME	=	push_swap

all:	${NAME}

${NAME}:$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

fclean:	clean
	rm -f $(NAME) $(NAME)~

clean:
	rm -f $(OBJ)
	rm -f $(TMP)
	rm -f Makefile~

re:	fclean ${NAME}
