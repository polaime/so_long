# /* ************************************************************************** */
# /*                                                     ..,,;;;,'..            */
# /*                                                 .'cx0XNNWWWNXKOdl;.        */
# /*   header_perso.c                              .;xXWNKOkkOKNMMMMMMW0l.      */
# /*                                              ,xNMXd,.   .cONMMMMMMMK;      */
# /*   Par: polaime <pthibaud>                   .:0WMX:      :XMMNNMMMMM0,     */
# /*                                             :KMMMk.      .lxdckMMMMWd.     */
# /*   Cree: 2025/01/19 13:50:28                ,OMMMMK,          ,0MMMWO'      */
# /*   Ameliore: 2025/01/19 14:42:13           .oWMMMMW0c.      .c0WMMWk,       */
# /*                                           'OMMWXNWMWKkddodkKWMMWKo.        */
# /*                                           'OMWk,,lx0XWWMMMMMWXOo'.         */
# /*   https://github.com/polaime              .oKx'    .';:clllc;'.            */
# /*                                                                            */
# /* ************************************************************************** */



#################################
## ARGUMENTS

NAME		= so_long
CFLAGS		= -g3 -Wall -Werror -Wextra
CC			= cc

#################################
## SOURCES

SRC_FILES 	=	so_long.c\
				

OBJ_FILES	= $(SRC_FILES:.c=.o)

#################################
## RULES
all: ${NAME}

${NAME}: ${OBJ_FILES} 
	@echo "\033[32mCompilation en cours...\033[0m"
	@${CC} ${CFLAGS} ${OBJ_FILES} -o ${NAME} > /dev/null 2>&1
	@sleep 1
	@echo "\033[32mCompilation terminee\033[0m"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@ > /dev/null 2>&1

clean: presentation
	@rm -f ${OBJ_FILES}
	@echo "\033[31mFichiers objets supprimés.\033[0m"

fclean: clean
	@rm -f ${NAME}
	@echo "\033[31mExecutable supprimé.\033[0m"

re: fclean all
.PHONY: all clean fclean re presentation