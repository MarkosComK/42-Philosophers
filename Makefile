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

clean:
	$(RM) $(OBJECTS)

re: clean all
