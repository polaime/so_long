#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

typedef struct s_textures {
	void	*floor;
	void	*wall;
	void	*player;
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
	char		**map;
	int			player_x;
	int			player_y;
	int			tile_size;
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
void		txtr_gest(char **tab, void *mlx, void *mlx_win);
void		txtr_gest2(t_textures tex, void *mlx, void *mlx_win, char **tab);
int			handle_key(int keycode, void *mlx, void *mlx_win, t_game game);

#endif