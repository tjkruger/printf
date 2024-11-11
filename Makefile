SRCSFT_PRINTF = libftprintf.c \
				ft_puthex.c \
				ft_putstr.c \
				ft_putnbr.c \
				ft_putunsigned.c \
				ft_putchar.c \
				ft_putptr.c \




SRC		= $(SRCSFT_PRINTF)

OBJ		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

OBJDIR	= obj
HEADER  = ft_printf.h
NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c $(HEADER) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I .

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
