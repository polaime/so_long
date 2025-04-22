#include "so_long.h"

char	**is_okay_to_open(int fd)
{
	char		*line;
	int			i;
	char		**tab;

	line = NULL;
	i = 0;
	tab = malloc(sizeof(char *) * 100000);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tab[i] = line;
		if (i > 0)
		{
			if (ft_strlen(tab[i]) != ft_strlen(tab[i - 1]))
				return (ft_putstr_fd("\ncant open this map (ÒДÓױ)\n", 1), NULL);
		}
		i++;
		line = get_next_line(fd);
	}
	return (tab);
}
