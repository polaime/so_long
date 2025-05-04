#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

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
void		see_error(t_check check, char **tab);
int			is_okay_to_open_wall(char **tab);
int			is_okay_to_open_wall_2(char **tab);
int			is_rectangular(char **tab);
void		find_player_game(t_game *game);
void		handle_key_utils(t_game *game, int x, int y);
void		player_on_exit(t_game *game, int y, int x);




#endif