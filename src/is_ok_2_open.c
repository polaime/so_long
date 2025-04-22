#include "so_long.h"

int	is_okay_to_open(char **argv)
{
	char		*line;
	int			fd;
	int			i;
	char		**tab;

	line = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	tab = malloc(sizeof(char *) * 100000);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tab[i] = line;
		if (i > 0)
		{
			if (ft_strlen(tab[i]) != ft_strlen(tab[i - 1]))
				return (ft_putstr_fd("cant open this map (ÒДÓױ)", 1), 1);
		}
		i++;
		line = get_next_line(fd);
	}
	return (0);
}
