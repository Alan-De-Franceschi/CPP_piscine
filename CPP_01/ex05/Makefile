NAME			=	harl

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
						Harl.cpp \

	
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

INCLUDES		=	Harl.hpp

# **************************************************************************** #
#                                                                              #
#                                  RULES                                       #
#                                                                              #
# **************************************************************************** #

all:  ${NAME}

${NAME}: ${OBJECTS} ${INCLUDES}
	@${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}
	@echo "${COLOUR_GREEN}\33[2K\nharl compiled with : \n${COLOUR_END}"
	@echo "	${CC} ${CFLAGS}\n"

${OBJECTS_PATH}%.o:	${SOURCES_PATH}%.cpp
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< -o $@ && printf "\33[2K\r${YELLOW}Compiling harl :${COLOUR_END} $@"

clean:
	@rm -rf ${OBJECTS_PATH}

fclean:
	@rm -rf ${OBJECTS_PATH}
	@rm -f ${NAME}
	@rm -f test.replace
	@echo "${COLOUR_GREEN}\nharl cleaned\n${COLOUR_END}"

re: fclean all

.PHONY: fclean clean all re