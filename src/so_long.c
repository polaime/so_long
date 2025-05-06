/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:20:43 by pthibaud          #+#    #+#             */
/*   Updated: 2025/05/05 14:20:45 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player_x(char **tab_dup)
{
	int		x;
	int		y;

	x = 0;
	while (tab_dup[x] != NULL)
	{
		y = 0;
		while (tab_dup[x][y] != 'P' && tab_dup[x][y] != '\0')
			y++;
		if (tab_dup[x][y] == 'P')
			break ;
		x++;
	}
	return (x);
}

int	find_player_y(char **tab_dup)
{
	int		x;
	int		y;

	x = 0;
	while (tab_dup[x] != NULL)
	{
		y = 0;
		while (tab_dup[x][y] != 'P' && tab_dup[x][y] != '\0')
			y++;
		if (tab_dup[x][y] == 'P')
			break ;
		x++;
	}
	return (y);
}

void	find_player_game(t_game *game)
{
	int		row;
	int		col;

	row = 0;
	while (game->map[row] != NULL)
	{
		col = 0;
		while (game->map[row][col] != 'P' && game->map[row][col] != '\0')
			col++;
		if (game->map[row][col] == 'P')
		{
			game->player_y = row;
			game->player_x = col;
			return ;
		}
		row++;
	}
}

void	find_exit_game(t_game *game)
{
	int		row;
	int		col;

	row = 0;
	while (game->map[row] != NULL)
	{
		col = 0;
		while (game->map[row][col] != 'E' && game->map[row][col] != '\0')
			col++;
		if (game->map[row][col] == 'E')
		{
			game->player_y = row;
			game->player_x = col;
			return ;
		}
		row++;
	}
}
