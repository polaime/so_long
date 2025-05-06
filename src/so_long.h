/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:20:49 by pthibaud          #+#    #+#             */
/*   Updated: 2025/05/06 11:14:49 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"

typedef struct s_textures {
	void	*flor;
	void	*wall;
	void	*plyr;
	void	*coin;
	void	*exit;
}				t_textures;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_check {
	int	collectibles_found;
	int	exit_found;
}				t_check;

typedef struct s_game {
	void		*mlx;
	void		*mlx_win;
	char		**map;
	int			player_x;
	int			player_y;
	int			tile_size;
	int			exit_x;
	int			exit_y;
	int			player_on_exit;
	int			on_collectible;
	int			steps;
	int			collectible;
	t_textures	textures;
}	t_game;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		win_gest(int i, int j, char **tab);
char		**is_okay_to_open(int fd);
int			main(int argc, char **argv);
int			help_to_know(int item, int player, int door);
int			is_okay_to_open_two(char **tab);
void		use_for_main(int fd);
int			other_letter(char **tab);
char		**tab_dupplicate(char **tab);
void		flood_fill(int x, int y, char **tab_dup, t_check *check);
char		**add_to_tab(char **tab, char *str);
void		txtr_gest(t_game *game);
void		txtr_gest2(t_textures tex, void *mlx, void *mlx_win, char **tab);
int			handle_key(int keycode, t_game *game);
int			find_player_x(char **tab_dup);
int			find_player_y(char **tab_dup);
void		see_error(t_check check, char **tab, int i, int j);
int			is_okay_to_open_wall(char **tab);
int			is_okay_to_open_wall_2(char **tab);
int			is_rectangular(char **tab);
void		find_player_game(t_game *game);
void		handle_key_utils(t_game *game, int x, int y);
void		player_on_exit(t_game *game, int y, int x);
void		exit_and_free(t_game *game);
void		exit_and_free2(t_game *game);
int			exit_and_free_hook(void *param);
void		txtr_gest_utils(t_textures *tex, t_game *game, int w, int h);
void		free_tab(char **tab);
void		free_tab_bis(char **tab, int max);
void		print_end(t_game *game);
void		handle_keykey(int keycode, t_game *game, int x, int y);
void		exit_and_free_bis(t_game *game, int nb, t_textures *tex);

#endif
