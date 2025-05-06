/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:19:56 by pthibaud          #+#    #+#             */
/*   Updated: 2025/05/06 12:46:38 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	exit_and_free(t_game *game)
{
	free_tab(game -> map);
	if (game && game->mlx && game -> textures.coin)
		mlx_destroy_image (game ->mlx, game->textures.coin);
	if (game -> textures.exit)
		mlx_destroy_image (game-> mlx, game->textures.exit);
	if (game -> textures.plyr)
		mlx_destroy_image (game ->mlx, game->textures.plyr);
	if (game -> textures.wall)
		mlx_destroy_image (game ->mlx, game->textures.wall);
	if (game -> textures.flor)
		mlx_destroy_image (game->mlx, game->textures.flor);
	exit_and_free2 (game);
}

void	exit_and_free_bis(t_game *game, int nb, t_textures *tex)
{
	free_tab(game -> map);
	if (nb > 0 && game->textures.flor)
	{
		free (game->textures.flor);
		mlx_destroy_image(game->mlx, game->textures.flor);
	}
	if (nb > 1 && game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (nb > 2 && game->textures.plyr)
		mlx_destroy_image(game->mlx, game->textures.plyr);
	if (nb > 3 && game->textures.coin)
		mlx_destroy_image(game->mlx, game->textures.coin);
	if (nb > 4 && game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	free (tex);
	exit_and_free2 (game);
}

void	exit_and_free2(t_game *game)
{
	if (game->mlx)
	{
		if (game->mlx_win)
			mlx_destroy_window(game->mlx, game->mlx_win);
		mlx_destroy_display(game->mlx);
		printf(">> mlx_destroy_display called\n");
		free(game->mlx);
	}
	free (game);
	exit(EXIT_FAILURE);
}

int	exit_and_free_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game && game->mlx)
		mlx_loop_end(game->mlx);
	exit_and_free(game);
	return (0);
}

void	free_tab(char **tab)
{
	int		i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	print_end(t_game *game)
{
	ft_printf("\n*******************************\n");
	ft_printf("*   Congratulations, you win!   *\n");
	ft_printf("*    You have completed the game! *\n");
	ft_printf("*******************************\n");
	ft_printf("\n-----------------------------\n");
	ft_printf("* Total steps taken: %d *\n", game->steps);
	ft_printf("-----------------------------\n");
}
