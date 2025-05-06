/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ok_2_open_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:20:18 by pthibaud          #+#    #+#             */
/*   Updated: 2025/05/05 14:20:20 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**tab_dupplicate(char **tab)
{
	int		tab_size;
	int		i;
	char	**tab_copy;

	tab_size = 0;
	i = 0;
	while (tab[tab_size] != NULL)
	{
		tab_size++;
	}
	tab_copy = ft_calloc(sizeof(char *), (tab_size + 1));
	if (!tab_copy)
		return (NULL);
	while (i < tab_size)
	{
		tab_copy[i] = ft_strdup(tab[i]);
		i++;
	}
	tab_copy[i] = NULL;
	return (tab_copy);
}

void	add_to_tab_utils(char **new_tab, char **old_tab, char *str, int len_old)
{
	int	i;

	i = 0;
	if (old_tab)
	{
		while (i < len_old)
		{
			new_tab[i] = old_tab[i];
			i++;
		}
	}
	new_tab[i] = str;
}

char	**add_to_tab(char **tab, char *str)
{
	int		len;
	char	**new_tab;
	int		i;

	i = 0;
	len = 0;
	new_tab = NULL;
	while (tab && tab[len])
		len++;
	new_tab = ft_calloc(sizeof(char *), (len + 2));
	if (!new_tab)
		return (NULL);
	add_to_tab_utils(new_tab, tab, str, len);
	if (tab)
		free(tab);
	new_tab[len + 1] = NULL;
	return (new_tab);
}

int	is_okay_to_open_wall(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[0][j] != '\n' && tab[0][j])
	{
		if (tab[0][j] != '1' && tab[0][j] != '\n')
			return (1);
		j++;
	}
	while (tab[i] != NULL)
	{
		if (tab[i][0] != '1' || tab[i][j - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	is_okay_to_open_wall_2(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i] != NULL)
		i++;
	i--;
	j = 0;
	while (tab[i][j])
	{
		if (tab[i][j] != '1' && tab[i][j] != '\n' && tab[i][j] != '\0')
			return (1);
		j++;
	}
	j = ft_strlen(tab[0]) - 1;
	while (i > 0)
	{
		if (tab[i][j] != '1' && tab[i][j] != '\n')
			return (1);
		i--;
	}
	return (0);
}
