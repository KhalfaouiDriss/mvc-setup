NAME = mvc-47
CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

install: $(NAME)
	@sleep 1
	@sudo cp $(NAME) /bin/
	@echo ""
	@echo "\033[1;32mInstalled successfully!\033[0m"
	@echo "\033[1;34mUsage:\033[0m  mvc-47 <project_name>"
	@echo "\033[1;33mExample:\033[0m mvc-47 myApp"
	@echo ""

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

src/%.o: src/%.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@echo "\033[1;31mObject files removed.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31mExecutable removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re
