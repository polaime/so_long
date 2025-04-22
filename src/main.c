#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!is_okay_to_open(argv))
			ft_putstr_fd("map ok ᕕ(╭ರ╭ ͟ʖ╮•́)⊃¤=(————-", 1);
		win_gest();
	}
	return (0);
}