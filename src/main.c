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
		tab = is_okay_to_open(fd);
		if (tab)
		{	
			ft_putstr_fd("\nmap ok ᕕ(╭ರ╭ ͟ʖ╮•́)⊃¤=(————-\n", 1);
			win_gest();
		}
		else
		{
			while (tab == NULL)
				free(tab[i++]);
		}
	}
	close(fd);
	return (0);
}