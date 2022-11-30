NAME	:= test
SRCS	:= $(wildcard zeGnl/*.c) test.c
OBJS	:= ${SRCS:.c=.o}

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -fno-omit-frame-pointer -g -O0 -fstack-protector-all -D BUFFER_SIZE=1
RM		:= rm -f

.PHONY: all
all: ${NAME}

${NAME}: ${OBJS}
	@echo "running name"
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.PHONY: clean
clean:
	${RM} ${OBJS}

.PHONY: fclean
fclean: clean
	${RM} ${NAME}

.PHONY: re
re: fclean all