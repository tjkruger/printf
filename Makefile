
SRCSFT_PRINTF = 




SRC		= $(SRCSFT_PRINTF)

OBJ		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

OBJDIR	= obj
HEADER  = ft_printf.h
NAME	= ft_printf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(NAME)
	ar -rcs $(NAME)

$(OBJDIR)/%.o: %.c $(HEADER) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I .

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all