NAME = lem-in
FLAGS = -Wall -Wextra -Werror -Winit-self -Wunreachable-code -Wformat-y2k	   \
-Wformat-nonliteral -Wformat-security -Wformat=2 -Wmissing-include-dirs 	   \
-Wswitch-default -Wtrigraphs -Wstrict-overflow=5 -Wfloat-equal -Wundef		   \
-Wshadow -Wbad-function-cast
SRC	= start.c room_parse.c tube_parse.c helpers.c
LIB	= ./libft/libft.a

all: $(NAME)

$(NAME): $(FRC)
	@make -C libft
	@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)
	@echo "\x1b[32mProject is successfully built!\x1b[0m"	

clean:
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re