#include "includes/so_long.h"

int main(int argc, char **argv)
{
    t_ut    ut;

    ut.map_name = argv[1];
    if (argc != 2)
        ft_putstr_fd("Error,\nwrong number of arguments", 0);
    else
        get_map_size(&ut);
    ft_free(&ut);
	// ft_destroy_text(&ut);

}