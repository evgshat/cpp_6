NAME	=	identify_real_type
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp Base.cpp
OBJS	=	${SRCS:.cpp=.o}
RM		=	rm -rf
HEADERS	=	Base.hpp

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} $^ -o $@

%.o: %.cpp Makefile ${HEADERS}
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
