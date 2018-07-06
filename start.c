#include "lem-in.h"

t_room	*get_end(t_room *start)
{
	t_room *cur;

	cur = start;
	while (cur != NULL)
	{
		if (cur->type == 2)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

int		main(void)
{
	int		len;
	int 	amount;
	int		*path;
	t_ants	*ants;
	t_room	*rooms;
	t_room	*end;	

	rooms = parse_farm(&amount);
	len = list_length(rooms);
	iterate_list(rooms, len);
	algorithm(rooms, len);
	end = get_end(rooms);
	path = end->way;
	ants = create_ants_list(amount);
	ft_putchar('\n');
	print_path(rooms, path, len);
	exit_ants(ants, rooms, path, len);
}
