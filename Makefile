CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
DEBUGFLAGS = -g3 -fsanitize=address
NAME	=	BSQ
SRCDIR	=	srcs/
SRCNAME =	*.c
INCDIR	=	srcs/

.c.o:
	$(CC) -c $(CFLAGS) -I $(INCDIR) $< -o $(<:.c=.o)

OBJS	=	$(addprefix  $(SRCDIR), $(SRCNAME:.c=.o))


all: 
	$(CC) $(CFLAGS) srcs/*.c -o $(NAME)

debug:
	$(CC) $(DEBUGFLAGS) srcs/*.c -o $(NAME)

clean:
	rm -f srcs/*.o

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean bsq fclean re
