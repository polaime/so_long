#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		win_gest(void);
char		**is_okay_to_open(int fd);
int			main(int argc, char **argv);
int			help_to_know(int item, int player, int door);
int			is_okay_to_open_two(char **tab);
void		use_for_main(int fd);



#endif