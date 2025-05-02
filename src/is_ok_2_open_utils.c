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
	tab_copy = malloc(sizeof(char *) * (tab_size + 1));
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

void add_to_tab_utils(char **new_tab,char **old_tab, char *str,int len_old)
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
	if (len != 0)
		free(tab);
	new_tab[len + 1] = NULL;

	return (new_tab);
}
