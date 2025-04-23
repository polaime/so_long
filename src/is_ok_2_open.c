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

int	is_okay_to_open_two(char **tab)
{
	int		i;
	int		j;
	int		item_is;
	int		player_is;
	int		door_is;

	i = 0;
	j = 0;
	item_is = 0;
	player_is = 0;
	door_is = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == 'E')
				door_is++;
			if (tab[i][j] == 'C')
				item_is++;
			if (tab[i][j] == 'P')
				player_is++;
			j++;
		}
		i++;
	}
	if (help_to_know(item_is, player_is, door_is) == 0)
		return (ft_putstr_fd("\ncant open this map (ÒДÓױ)0\n\n", 1), 0);
	return (1);
}

int	help_to_know(int item, int player, int door)
{
	if (item < 1 || player == 1 || door == 1)
		return (1);
	else
		return (0);
}
