#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**tab;

	tab = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		if (i <= 4)
			return (close (fd), 0);
		if (argv[1][i - 4] != '.' && argv[1][i - 3] != 'b' &&
					argv[1][i - 2] != 'e' && argv[1][i - 1] != 'r')
		{
			ft_putstr_fd("wrong map ext (╥﹏╥)\n", 1);
			return (close (fd), 0);
		}
		else
			use_for_main(fd);
	}
	close(fd);
	return (0);
}

void	use_for_main(int fd)
{
	char		**tab;
	char		**tab_dup;
	int			i;
	int			j;
	t_check		check;

	i = 0;
	check.exit_found = 0;
	tab = is_okay_to_open(fd);
	j = ft_strlen(tab[i]);
	while (tab[i] != NULL)
		i++;
	tab_dup = tab_dupplicate(tab);
	flood_fill(find_player_x(tab), find_player_y(tab), tab_dup, &check);
	if (check.exit_found == 1
		&& check.collectibles_found == is_okay_to_open_two(tab))
	{
		if (tab && is_okay_to_open_two(tab) != 0 && other_letter(tab) != 0)
		{
			{
				ft_putstr_fd("\nmap ok ᕕ(╭ರ╭ ͟ʖ╮•́)⊃¤=(————-\n", 1);
				win_gest(i, j - 1, tab);
			}
		}
	}
}

void	see_error(t_check check, char **tab)
{
	int		collectible;

	collectible = is_okay_to_open_two(tab);

	if (check.exit_found != 1 || check.collectibles_found != collectible)
		ft_putstr_fd("Noooo cant play on this map ヽ(｀Д´)ﾉ", 1);
}
