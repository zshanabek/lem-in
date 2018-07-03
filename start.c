#include "lem-in.h"

int		*get_path(t_room *start)
{
	t_room *cur;

	cur = start;
	while (cur != NULL)
	{
		if (cur->type == 2)
			return (cur->way);
		cur = cur->next;
	}
	return (0);
}

void	exit_ants(int *path)
{
	
}

int		main(void)
{
	int		len;
	int 	amount;
	int		*path;
	t_ants	*ants;
	t_room	*rooms;

	rooms = parse_farm(&amount);
	len = list_length(rooms);
	iterate_list(rooms, len);
	algorithm(rooms, len);
	path = get_path(rooms);
	ft_print1dintarr(path, len);
	ants = create_ants_list(amount);
	print_ants_list(ants);	
}
