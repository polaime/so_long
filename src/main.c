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
		use_for_main(fd);
	}
	close(fd);
	return (0);
}
void use_for_main(int fd)
{
	char		**tab;

	tab = is_okay_to_open(fd);
	if (tab && is_okay_to_open_two(tab) != 0 && other_letter(tab) != 0)
	{	
		ft_putstr_fd("\nmap ok ᕕ(╭ರ╭ ͟ʖ╮•́)⊃¤=(————-\n", 1);
		win_gest();
	}
}