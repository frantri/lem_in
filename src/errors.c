#include <lem_in.h>
#include <stdlib.h>
#include <ft_printf.h>

t_parsing_msg	exit_error(char *msg)
{
	ft_dprintf(2, "ERROR: %s\n", msg);
	exit(1);
}
