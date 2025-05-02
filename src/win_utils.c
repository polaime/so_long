#include "so_long.h"

int	handle_key(int keycode, void *mlx, void *mlx_win, t_game game)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx, mlx_win);
	else if (keycode == 119)
		game.player_y--;
	else if (keycode == 115)
		game.player_y++;
	else if (keycode == 97)
		game.player_x--;
	else if (keycode == 100)
		game.player_x++;
	return (0);
}