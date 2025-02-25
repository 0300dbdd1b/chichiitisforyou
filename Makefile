CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
DEBUGFLAGS = -g3 -fsanitize=leak
NAME	=	BSQ
SRCDIR	=	srcs/
SRCNAME =	allocator.c		\
			file-utils.c	\
			ft_join.c		\
			ft_split.c		\
			main.c			\
			map.c			\
			map-checker.c	\
			print-utils.c	\
			square-finder.c	\
			stdlib-utils.c	\
			bsq.c			\

INCDIR	=	srcs/

.c.o:
	$(CC) -c $(CFLAGS) -I $(INCDIR) $< -o $(<:.c=.o)

OBJS	=	$(addprefix  $(SRCDIR), $(SRCNAME:.c=.o))


all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME): all

debug: $(OBJS)
	$(CC) $(DEBUGFLAGS) $(OBJS)  -o $(NAME)
	rm -f $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

x:	fclean all clean

re: fclean all

.PHONY:	all clean bsq fclean x re
