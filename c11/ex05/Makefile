NAME = do-op

SRCS = calculator.c\
	   ft_do_op.c\
	   ft_atoi.c\

INCLUDES = ft.h

OBJS = ${SRCS:.c=.o}

RM = rm -f
CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:		${NAME}

${NAME}:  	${OBJS} ${INCLUDES}
			${CC} ${CFLAGS} ${OBJS} -o do-op
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
