NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c outils.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strlen.c ft_tolower.c

HEADER = ft_printf.h
OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)	
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
