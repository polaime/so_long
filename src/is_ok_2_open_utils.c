char	**tab_dupplicate(char **tab, int fd)
{
	char	**tab_dupplicate;
	int		i;

	i = 0;
	tab_dupplicate = malloc(sizeof(char *) * 100000);
	if (!tab_dupplicate)
		return (0);
	tab_dupplicate[i] = get_next_line(fd);
	while (tab_dupplicate[i] != NULL)
	{
		i++;
		tab_dupplicate[i] = get_next_line(fd);
	}
	return (tab_dupplicate);
}
void valid_map(t_solong *game, fd)
{
	char	**tab_dup;
	int		x;
	int		y;

	y = 0;
	x = 0;
	tab_dup = tab_dupplicate(tab, fd);
	while (tab_dup[x] != 0)
	{
		y = 0;
		while (tab_dup[x][y] != 'P')
			y++;
		x++;
	}
}
