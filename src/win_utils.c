/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:21:06 by pthibaud          #+#    #+#             */
/*   Updated: 2025/05/06 10:11:37 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	handle_keykey(keycode, game, x, y);
	if (game->on_collectible == is_okay_to_open_two(game -> map)
		&& game->map[game->player_y][game->player_x] == 'E')
	{
		print_end(game);
		exit_and_free(game);
	}
	player_on_exit(game, y, x);
	game->map[game->player_y][game->player_x] = 'P';
	txtr_gest2(game->textures, game->mlx, game->mlx_win, game->map);
	return (0);
}

void	player_on_exit(t_game *game, int y, int x)
{
	if (game->player_on_exit)
		game->map[y][x] = 'E';
	else
		game->map[y][x] = '0';
	if (game->map[game->player_y][game->player_x] == 'E')
		game->player_on_exit = 1;
	else
		game->player_on_exit = 0;
	if (game->on_collectible)
		game ->on_collectible++;
}

void	handle_keykey(int keycode, t_game *game, int x, int y)
{
	if (keycode == 65307)
		exit_and_free(game);
	else if (keycode == 119 && game->map[y - 1][x] != '1')
	{
		game->player_y--;
		ft_printf("%i\n", game ->steps++);
	}
	else if (keycode == 115 && game->map[y + 1][x] != '1')
	{
		game->player_y++;
		ft_printf("%i\n", game ->steps++);
	}
	else if (keycode == 97 && game->map[y][x - 1] != '1')
	{
		game->player_x--;
		ft_printf("%i\n", game ->steps++);
	}
	else if (keycode == 100 && game->map[y][x + 1] != '1')
	{
		game->player_x++;
		ft_printf("%i\n", game ->steps++);
	}
}
