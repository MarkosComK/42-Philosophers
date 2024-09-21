RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
WHITE  = $(shell printf "\33[37m")
YELLOW = $(shell printf "\33[33m")
RESET  = $(shell printf "\33[0m")
BLUE = $(shell printf "\33[34m")
PURPLE = $(shell printf "\33[35m")
TITLE = $(shell printf "\33[32;40m")

SOURCES_FILES	=	so_long.c \

SOURCES_DIR		=	sources
BONUS_DIR		=	bonus

HEADER			=	philo.h

SOURCES			=	$(wildcard *.c)

OBJECTS			= $(SOURCES:.c=.o)

NAME			=	philo

CC				=	cc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -g 
#-fsanitize=thread

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJECTS) $(HEADER)
		@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
		@clear
		@echo "$(PURPLE)"
		@sleep 0.1
		@echo " ██▓███   ██░ ██  ██▓ ██▓     ▒█████    ██████  ▒█████   ██▓███   ██░ ██ ▓█████  ██▀███    ██████    "
		@sleep 0.1
		@echo "▓██░  ██▒▓██░ ██▒▓██▒▓██▒    ▒██▒  ██▒▒██    ▒ ▒██▒  ██▒▓██░  ██▒▓██░ ██▒▓█   ▀ ▓██ ▒ ██▒▒██    ▒    "
		@sleep 0.1
		@echo "▓██░ ██▓▒▒██▀▀██░▒██▒▒██░    ▒██░  ██▒░ ▓██▄   ▒██░  ██▒▓██░ ██▓▒▒██▀▀██░▒███   ▓██ ░▄█ ▒░ ▓██▄      "
		@sleep 0.1
		@echo "▒██▄█▓▒ ▒░▓█ ░██ ░██░▒██░    ▒██   ██░  ▒   ██▒▒██   ██░▒██▄█▓▒ ▒░▓█ ░██ ▒▓█  ▄ ▒██▀▀█▄    ▒   ██▒   "
		@sleep 0.1
		@echo "▒██▒ ░  ░░▓█▒░██▓░██░░██████▒░ ████▓▒░▒██████▒▒░ ████▓▒░▒██▒ ░  ░░▓█▒░██▓░▒████▒░██▓ ▒██▒▒██████▒▒   "
		@sleep 0.1
		@echo "▒▓▒░ ░  ░ ▒ ░░▒░▒░▓  ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ▒▓▒░ ░  ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒▓ ░▒▓░▒ ▒▓▒ ▒ ░   "
		@sleep 0.1
		@echo "░▒ ░      ▒ ░▒░ ░ ▒ ░░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░  ░ ▒ ▒░ ░▒ ░      ▒ ░▒░ ░ ░ ░  ░  ░▒ ░ ▒░░ ░▒  ░ ░   "
		@sleep 0.1
		@echo "░░        ░  ░░ ░ ▒ ░  ░ ░   ░ ░ ░ ▒  ░  ░  ░  ░ ░ ░ ▒  ░░        ░  ░░ ░   ░     ░░   ░ ░  ░  ░     "
		@sleep 0.1
		@echo "          ░  ░  ░ ░      ░  ░    ░ ░        ░      ░ ░            ░  ░  ░   ░  ░   ░           ░     $(GREEN)"
		@sleep 0.1
		@echo "                                  ⠀⠀⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠟⢀⡀⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⢿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠟⢁⣴⡿⠃⣠⡀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⠈⢿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣅⣴⡿⠋⣠⡾⠋⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⠀⠈⢻⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣤⡾⠋⠀⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣦⡀⠀⠀⠀⢀⣼⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⢿⣿⣿⣿⣦⡀⠰⣿⣿⠟⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠙⢿⣿⣦⡈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣷⡄⠙⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣿⣿⡿⠋⠀⠈⠻⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⡿⠋⠀⠀⠀⠀⠀⠘⢿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⠀⠀⣠⣾⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⣠⣾⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣦⡀⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⢸⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣿⣿⠀⠀⠀"
		@sleep 0.1
		@echo "⠀                                ⠀⠀⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠉⠀⠀⠀"
		@sleep 0.1
		@echo
		@sleep 0.1
		@echo "                                      ℹ️ $(YELLOW) Dinner is ready! 🍽️.$(RESET)"
		@sleep 0.1
		@echo
		@sleep 0.1

clean:
	@$(RM) $(OBJECTS)
	     @clear 
	@echo 
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓" 
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃" 
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛" 
	@echo

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all
