NAME	:= test
SRCS	:= $(wildcard zeGnl/*.c) test.c
OBJS	:= ${SRCS:.c=.o}

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -fno-omit-frame-pointer -g -O0 -fstack-protector-all -D BUFFER_SIZE=1000000
RM		:= rm -f

ifeq ("$(uname -r)", "5.10.104-linuxkit")
  LBSD := -lbsd
  FSANITIZE := -fsanitize=address -fsanitize=leak
else
  LBSD :=
  FSANITIZE :=
endif

.PHONY: all
all: ${NAME}

${NAME}: ${OBJS}
	@echo "running name"
	${CC} ${CFLAGS} ${FSANITIZE} ${OBJS} -o ${NAME} ${LBSD}

.PHONY: clean
clean:
	${RM} ${OBJS}

.PHONY: fclean
fclean: clean
	${RM} ${NAME}

docker_build:
	docker build -t gnl .

docker_run:
	docker run -it gnl

docker_clean:
	docker system prune -a --volumes

.PHONY: re
re: fclean all