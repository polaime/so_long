/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:20:33 by pthibaud          #+#    #+#             */
/*   Updated: 2025/05/06 12:35:59 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**tab;

	tab = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || open(argv[1], O_RDONLY) == -1)
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

int	check_len_tab(char **tab)
{
	size_t	len;
	int		i;

	i = 1;
	len = ft_strlen(tab[0]);
	while (tab[i])
	{
		if (ft_strlen(tab[i]) != len)
		{
			free_tab(tab);
			return (-1);
		}
		i++;
	}
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
	check.collectibles_found = 0;
	tab = is_okay_to_open(fd);
	if (!tab)
		return ;
	if (check_len_tab(tab) == -1)
	{
		printf("probleme\n");
		return ;
	}
	j = ft_strlen(tab[i]);
	while (tab[i] != NULL)
		i++;
	tab_dup = tab_dupplicate(tab);
	flood_fill(find_player_x(tab), find_player_y(tab), tab_dup, &check);
	free_tab(tab_dup);
	see_error(check, tab, i, j);
}

void	see_error(t_check check, char **tab, int i, int j)
{
	if (check.exit_found == 1
		&& check.collectibles_found == is_okay_to_open_two(tab))
	{
		if (tab && is_okay_to_open_two(tab) != 0 && other_letter(tab) != 0
			&& is_okay_to_open_wall(tab) != 1
			&& is_okay_to_open_wall_2(tab) != 1)
		{
			{
				ft_putstr_fd("\nmap ok ᕕ(╭ರ╭ ͟ʖ╮•́)⊃¤=(————-\n", 1);
				win_gest(i, j - 1, tab);
			}
		}
		else
		{
			ft_putstr_fd("\ncant open this map (ÒДÓױ)0\n\n", 1);
			free_tab(tab);
		}
	}
	else
	{
		ft_putstr_fd("Noooo cant play on this map ヽ(｀Д´)ﾉ", 1);
		free_tab(tab);
	}
}
