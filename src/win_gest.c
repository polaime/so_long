/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_gest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:20:59 by pthibaud          #+#    #+#             */
/*   Updated: 2025/05/06 12:48:46 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_gest(int x, int y, char **tab)
{
	t_game		*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return ;
	game = ft_memset(game, 0, sizeof(t_game));
	game->collectible = is_okay_to_open_two(tab);
	game->map = tab;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free(game), (void)0);
	game->mlx_win = mlx_new_window(game->mlx, y * 32, x * 32, "SO_LONG");
	if (!game->mlx_win)
		return (free(game->mlx), free(game), (void)0);
	txtr_gest(game);
	find_player_game(game);
	mlx_hook(game ->mlx_win, 17, 0, exit_and_free_hook, game);
	mlx_key_hook(game->mlx_win, handle_key, game);
	mlx_loop(game->mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	txtr_gest(t_game *game)
{
	t_textures	*tex;
	int			w;
	int			h;

	tex = malloc(sizeof(t_textures));
	if (!tex)
		return ;
	tex->flor = mlx_xpm_file_to_image
		(game->mlx, "sprites/texture/floor.xpm", &w, &h);
	tex->wall = mlx_xpm_file_to_image
		(game->mlx, "sprites/texture/wall.xpm", &w, &h);
	txtr_gest_utils(tex, game, w, h);
	game->textures = *tex;
	txtr_gest2 (game -> textures, game->mlx, game->mlx_win, game->map);
	free(tex);
}

void	txtr_gest_utils(t_textures *tex, t_game *game, int w, int h)
{
	tex->plyr = mlx_xpm_file_to_image
		(game->mlx, "sprites/perso/front.xpm", &w, &h);
	tex->coin = mlx_xpm_file_to_image(game->mlx,
			"sprites/texture/coin-bag.xpm", &w, &h);
	tex->exit = mlx_xpm_file_to_image(game->mlx,
			"sprites/texture/exit-closed.xpm", &w, &h);
	if (!tex->exit || !tex->coin || !tex->flor || !tex->wall || !tex->plyr)
	{
		exit_and_free_bis(game, 5, tex);
	}
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
