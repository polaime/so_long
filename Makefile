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
CFLAGS		= -g3 -Wall -Werror -Wextra -I$(MLX_DIR) -Iget_next_line -Ilibft
LDFLAGS		= -Lminilibx-linux -lmlx -lXext -lX11 -lm
CC			= cc

#################################
## SOURCES

SRC_DIRS		=	get_next_line libft src
BUILD_DIR	=	build
MLX_DIR 	=	minilibx-linux
SRCS = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))
NAME = so_long

#################################
## RULES
all: $(MLX_DIR)/libmlx.a ${NAME}

${NAME}: ${OBJS} 
	@echo "\033[32mCompilation en cours...\033[0m"
	@${CC} ${CFLAGS} ${OBJS} -o $@ $(LDFLAGS) > /dev/null 2>&1
	@echo "\033[32mCompilation terminee\033[0m"

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -rf ${BUILD_DIR}
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[31mFichiers et dossier objets supprimés.\033[0m"

fclean: clean
	@rm -f ${NAME}
	@echo "\033[31mExecutable supprimé.\033[0m"

re: fclean all

.PHONY: all clean fclean re 