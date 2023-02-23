SERVER_NAME = server
SERVER_SRC = server.c

CLIENT_NAME = client
CLIENT_SRC = client.c

BONUS_SERVER_NAME = server_bonus
BONUS_SERVER_SRC = server_bonus.c

BONUS_CLIENT_NAME = client_bonus
BONUS_CLIENT_SRC = client_bonus.c

UTILS_SRC = minitalk_utils.c

CC = gcc
FLAGS = -Wall -Werror -Wextra

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:		$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):
			$(CC) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER_NAME) $(FLAGS)
			@echo "$(GREEN)server compiled!$(DEF_COLOR)"

$(CLIENT_NAME):
			$(CC) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT_NAME) $(FLAGS)
			@echo "$(GREEN)client compiled!$(DEF_COLOR)"

clean:
			@rm -f $(SERVER_NAME) $(CLIENT_NAME)
			@rm -f $(BONUS_SERVER_NAME) $(BONUS_CLIENT_NAME)
			@echo "$(CYAN)cleaned the object files!$(DEF_COLOR)"

fclean:		clean
			@echo "$(BLUE)cleaned ALL!$(DEF_COLOR)"

re:			fclean all
			@echo "$(RED)recompiled!$(DEF_COLOR)"

bonus:		$(BONUS_SERVER_NAME) $(BONUS_CLIENT_NAME)

$(BONUS_SERVER_NAME):
			$(CC) $(BONUS_SERVER_SRC) $(UTILS_SRC) -o $(BONUS_SERVER_NAME) $(FLAGS)
			@echo "$(YELLOW)bonus server compiled!$(DEF_COLOR)"

$(BONUS_CLIENT_NAME):
			$(CC) $(BONUS_CLIENT_SRC) $(UTILS_SRC) -o $(BONUS_CLIENT_NAME) $(FLAGS)
			@echo "$(YELLOW)bonus client compiled!$(DEF_COLOR)"
