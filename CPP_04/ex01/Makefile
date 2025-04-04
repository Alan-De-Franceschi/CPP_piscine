NAME			=	polym

CFLAGS			=	-Wall -Wextra -Werror -I INCLUDES -std=c++98

CC				=	c++

COLOUR_GREEN	=	\033[0;32m

YELLOW			=	\033[0;33m

COLOUR_END		=	\033[0m

# **************************************************************************** #
#                                                                              #
#                                  SOURCES                                     #
#                                                                              #
# **************************************************************************** #

SOURCES_PATH	=	./

SOURCES_MAIN	= 	main.cpp \
						Animal.cpp \
						Dog.cpp \
						Cat.cpp \
						Brain.cpp \
						WrongAnimal.cpp \
						WrongCat.cpp \

	
# **************************************************************************** #
#                                                                              #
#                                  OBJECTS                                     #
#                                                                              #
# **************************************************************************** #

OBJECTS_PATH	=	objs/

OBJECTS			=	$(addprefix ${OBJECTS_PATH}, ${SOURCES_MAIN:.cpp=.o}) \

# **************************************************************************** #
#                                                                              #
#                                  INCLUDES                                    #
#                                                                              #
# **************************************************************************** #

INCLUDES		=	Animal.hpp \
						Dog.hpp \
						Cat.hpp \
						Brain.hpp \
						WrongAnimal.hpp \
						WrongCat.hpp \

# **************************************************************************** #
#                                                                              #
#                                  RULES                                       #
#                                                                              #
# **************************************************************************** #

all:  ${NAME}

${NAME}: ${OBJECTS} ${INCLUDES}
	@${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}
	@echo "${COLOUR_GREEN}\33[2K\npolym compiled with : \n${COLOUR_END}"
	@echo "	${CC} ${CFLAGS}\n"

${OBJECTS_PATH}%.o:	${SOURCES_PATH}%.cpp
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< -o $@ && printf "\33[2K\r${YELLOW}Compiling polym :${COLOUR_END} $@"

clean:
	@rm -rf ${OBJECTS_PATH}

fclean:
	@rm -rf ${OBJECTS_PATH}
	@rm -f ${NAME}
	@echo "${COLOUR_GREEN}\npolym cleaned\n${COLOUR_END}"

re: fclean all

.PHONY: fclean clean all re