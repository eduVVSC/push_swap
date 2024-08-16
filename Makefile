NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/sorting1.c srcs/sorting2.c srcs/sorting.c srcs/utils.c srcs/utils2.c srcs/utils3.c srcs/functions.c srcs/functions2.c srcs/main.c

LIBS = srcs/libs/libft/libft.a srcs/libs/ft_printf/libftprintf.a srcs/libs/gnl/gnl.a

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C srcs/libs/libft
	@make -C srcs/libs/ft_printf
	@make -C srcs/libs/gnl
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "-->Objects created<--"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C srcs/libs/ft_printf
	@make clean -C srcs/libs/libft
	@make clean -C srcs/libs/gnl
	@rm -f $(OBJ)
	@echo "->Objects cleaned<-"

fclean: clean
	@make fclean -C srcs/libs/ft_printf
	@make fclean -C srcs/libs/libft
	@make fclean -C srcs/libs/gnl
	@rm -f $(NAME)
	@echo "->$(NAME) erase<-"

re: fclean all

.PHONY: all clean fclean re
