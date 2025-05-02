#include "so_long.h"

void	win_gest(int x, int y, char **tab)
{
	void		*mlx;
	void		*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, y * 32, x * 32, "SO_LONG");
	txtr_gest(tab, mlx, mlx_win);
	mlx_key_hook(mlx_win, handle_key, mlx);
	mlx_loop(mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	txtr_gest(char **tab, void *mlx, void *mlx_win)
{
	t_textures	tex;
	int			w;
	int			h;

	tex.floor = mlx_xpm_file_to_image(mlx, "sprites/texture/floor.xpm", &w, &h);
	tex.wall = mlx_xpm_file_to_image(mlx, "sprites/texture/wall.xpm", &w, &h);
	tex.player = mlx_xpm_file_to_image(mlx, "sprites/perso/front.xpm", &w, &h);
	tex.coin = mlx_xpm_file_to_image(mlx,
			"sprites/texture/coin-bag.xpm", &w, &h);
	tex.exit = mlx_xpm_file_to_image(mlx,
			"sprites/texture/exit-closed.xpm", &w, &h);
	txtr_gest2 (tex, mlx, mlx_win, tab);
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
				mlx_put_image_to_window(mlx, mlx_win,
					tex.floor, j * 32, i * 32);
			else if (tab[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win,
					tex.player, j * 32, i * 32);
			else if (tab[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, tex.coin, j * 32, i * 32);
			else if (tab[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, tex.exit, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

// void	ft_moove(t_textures tex, void *mlx, void *mlx_win, char **tab)
// {
// 	int		x;
// 	int		y;

// 	x = 0;
// 	y = 0;
// 	while (tab[x] != NULL)
// 	{
// 		y = 0;
// 		while (tab[x][y] != 'P' && tab[x][y] != '\0')
// 			y++;
// 		if (tab[x][y] == 'P')
// 			break ;
// 		x++;
// 	}
// }
