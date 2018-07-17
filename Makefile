NAME = lem-in
FLAGS = -Wall -Wextra -Werror
SRC	= start.c parsing.c links.c helpers.c algorithm.c quit.c utils.c auxil.c
LIB	= ./libft/libft.a

all: $(NAME)

$(NAME): $(FRC)
	@make -C libft
	@gcc $(SRC) $(LIB) -o $(NAME)
	@echo "\x1b[32mProject is successfully built!\x1b[0m"	

clean:
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re