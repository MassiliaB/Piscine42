NAME = libft.a

SRCS = ${FOLDER}ft_putchar.c\
	   ${FOLDER}ft_swap.c\
	   ${FOLDER}ft_putstr.c\
	   ${FOLDER}ft_strlen.c\
	   ${FOLDER}ft_strcmp.c 
FOLDER = ./srcs/

HEADER = includes/

INCLUDES = includes/ft.h

OBJS = ${SRCS:.c=.o}

RM = rm -f
CC = gcc 

CFLAGS = -Wall -Wextra -Werror

all:		${NAME}

${NAME}:  	${OBJS} ${INCLUDES}
			ar -rc ${NAME} ${OBJS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${HEADER}

clean: 
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
