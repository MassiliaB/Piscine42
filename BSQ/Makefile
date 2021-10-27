CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRCS		= ft_open_file.c \
			  ft_split.c \
			  calculator_map.c \
			  fill_from_file.c \
			  search.c \
			  ft_tools.c \
			  fill_dist.c

NAME		= bsq
OBJS		= ${SRCS:.c=.o}

%.o:		%.c
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean
