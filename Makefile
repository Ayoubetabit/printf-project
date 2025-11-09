NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c outils.c
HEADER = ft_printf.h
OBJ = $(SRC:.c=.o)

LIBFTPATH = ./libft/libft.a
LIBFT = libft.a
all : $(NAME)
$(NAME) : $(OBJ)
	make -C libft
	cp $(LIBFTPATH) .
	ar x $(LIBFT)
	ar rcs $(NAME) $(OBJ) *.o
	rm -f *.o
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJ)
	make -C libft clean
fclean : clean
	rm -f $(NAME) $(LIBFT)
	make -C libft fclean
re : fclean all
