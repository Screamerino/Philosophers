NAME		=	philo

SRC_PATH 	=	src/
SRC_FILES	=	start.c		utils.c		init.c\
				print.c		free.c		action.c\
				routines.c	
SRC			=	${addprefix ${SRC_PATH}, ${SRC_FILES}}
INC_PATH 	=	inc/
INC_FILES	= 	philo.h
INC			=	${addprefix ${INC_PATH}, ${INC_FILES}}
OBJ			=	${SRC:%.c=%.o}

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I${INC_PATH}

.PHONY	:	all clean fclean re bonus

all		:	${NAME}

${NAME}	:	${OBJ} ${INC}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

%.o : %.c ${INC}
	${CC} ${CFLAGS} -c $< -o $@

clean	:
	rm -f ${OBJ}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all