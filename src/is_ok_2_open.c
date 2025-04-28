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
	item_is = 0;
	player_is = 0;
	door_is = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j++] != '\0')
		{
			if (tab[i][j] == 'E')
				door_is++;
			if (tab[i][j] == 'C')
				item_is++;
			if (tab[i][j] == 'P')
				player_is++;
		}
		i++;
	}
	return (help_to_know(item_is, player_is, door_is));
}

int	help_to_know(int item, int player, int door)
{
	if (item < 1 || player != 1 || door != 1)
		return (ft_putstr_fd("\ncant open this map (ÒДÓױ)0\n\n", 1), 0);
	else
		return (1);
}

int	other_letter(char **tab)
{
	int		i;
	int		j;
	int		other;

	other = 0;
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j++] != '\0')
		{
			if (tab[i][j] != 'E' && tab[i][j] != 'P' && tab[i][j] != 'C' &&
					tab[i][j] != '1' && tab[i][j] != '0' && tab[i][j] != '\n'
					&& tab[i][j] != '\0')
				other++;
		}
		i++;
	}
	if (other != 0)
		return (ft_putstr_fd("\ncant open this map (ÒДÓױ)1\n\n", 1), 0);
	else
		return (1);
}

int	flood_fill(int x, int y, char **tab_dup, t_check *check)
{
	while (tab_dup[x])
	{
		y = 0;
		while (tab_dup[x][y] != 'P' && tab_dup[x][y] != '\0')
			y++;
		x++;
	}
	if (tab_dup[x][y] == '1' || tab_dup[x][y] == 'X')
		return ;
	if (tab_dup[x][y] == 'C')
		check -> collectibles_found++;
	if (tab_dup[x][y] == 'E')
		check -> exit_found = 1;
	[y][x] = 'V';

}

