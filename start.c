#include "lem-in.h"

int		main(void)
{
	int		len;
	int 	amount;
	t_ants	*ants;
	t_room	*rooms;

	rooms = parse_farm(&amount);
	len = list_length(rooms);	
	iterate_list(rooms, len);
	algorithm(rooms, len);
	ants = create_ants_list(amount);
	ft_putchar('\n');
	exit_ants(ants, rooms, len);
}
