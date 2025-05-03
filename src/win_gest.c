#include "so_long.h"

void	win_gest(int x, int y, char **tab)
{
	t_game		*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return ;
	game->map = tab;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, y * 32, x * 32, "SO_LONG");
	find_player_game(game);
	txtr_gest(game);
	mlx_key_hook(game->mlx_win, handle_key, game);
	mlx_loop(game->mlx);
	free (game);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	txtr_gest(t_game *game)
{
	t_textures	tex;
	int			w;
	int			h;

	tex.flor = mlx_xpm_file_to_image
		(game->mlx, "sprites/texture/floor.xpm", &w, &h);
	tex.wall = mlx_xpm_file_to_image
		(game->mlx, "sprites/texture/wall.xpm", &w, &h);
	tex.plyr = mlx_xpm_file_to_image
		(game->mlx, "sprites/perso/front.xpm", &w, &h);
	tex.coin = mlx_xpm_file_to_image(game->mlx,
			"sprites/texture/coin-bag.xpm", &w, &h);
	tex.exit = mlx_xpm_file_to_image(game->mlx,
			"sprites/texture/exit-closed.xpm", &w, &h);
	game->textures = tex;
	txtr_gest2 (tex, game->mlx, game->mlx_win, game->map);
}

void	txtr_gest2(t_textures tex, void *mlx, void *mlx_win, char **tab)
{
	int		j;
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, tex.wall, j * 32, i * 32);
			else if (tab[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_win, tex.flor, j * 32, i * 32);
			else if (tab[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, tex.plyr, j * 32, i * 32);
			else if (tab[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, tex.coin, j * 32, i * 32);
			else if (tab[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, tex.exit, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

