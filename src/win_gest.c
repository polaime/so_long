#include "so_long.h"

void	win_gest(void)
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, "sprites/player.xpm", &img_width, &img_height);
	if (!img)
		return (1);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 100);
	mlx_loop(mlx);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
