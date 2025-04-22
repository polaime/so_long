# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 14:36:32 by pthibaud          #+#    #+#              #
#    Updated: 2025/01/14 15:44:45 by pthibaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#################################
## ARGUMENTS

NAME		= libftprintf.a
CFLAGS		= -Wall -Werror -Wextra
CC			= cc

#################################
## SOURCES

SRC_FILES 	=	ft_printf_tools.c\
				ft_printf_utils.c\
				ft_printf.c\

OBJ_FILES	= $(SRC_FILES:.c=.o)

#################################
## RULES

all: ${NAME}

${NAME}: ${OBJ_FILES}
	ar rcs ${NAME} ${OBJ_FILES}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ_FILES}
fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

