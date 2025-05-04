#include "so_long.h"

int	handle_key(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (keycode == 65307)
		mlx_destroy_window(game->mlx, game->mlx_win);
	else if (keycode == 119 && game->map[y - 1][x] != '1')
		game->player_y--;
	else if (keycode == 115 && game->map[y + 1][x] != '1')
		game->player_y++;
	else if (keycode == 97 && game->map[y][x - 1] != '1')
		game->player_x--;
	else if (keycode == 100 && game->map[y][x + 1] != '1')
		game->player_x++;
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
}

