NAME = philo_bonus

CC = gcc
CFLAGS =  -g3 -fsanitize=thread
#-Wall -Wextra -Werror
RM = rm -f

INCLUDE = -Iinclude -pthread

MAIN = main.c
SRCS = actions.c error_handler.c init.c launcher.c queueing.c utils.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${INCLUDE} -o ${NAME} ${MAIN} ${OBJS}

%.o: %.c
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re