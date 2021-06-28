#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_ut ut;

	ut.map_name = argv[1];
	if (ft_check_ber(&ut) == 1)
	{
		if (argc != 2)
			ft_putstr_fd("Error,\nwrong number of arguments", 0);
		else
			get_map_size(&ut);
		ft_free(&ut);
	}
}

int	ft_check_ber(t_ut *ut)
{
	int	i;

	i = 0;
	while (ut->map_name[i])
		i++;
	if (ut->map_name[i - 1] == 'r' && ut->map_name[i - 2] == 'e' && ut->map_name[i - 3] == 'b'
		&& ut->map_name[i - 4] == '.')
	{
		return (1);
	}
	else
		ft_putstr_fd("Error\nfile is not .ber", 0);
	return (0);
}