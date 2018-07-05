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

int		is_everybody_outside(t_ants *start, int end)
{
	t_ants *cur;

	cur = start;
	while (cur != NULL)
	{
		if (cur->pos != end)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	move_ants(t_ants *head, int *path, int len)
{
	static int i = 0;
	t_ants	*cur;
	int		s;

	s = 0;
	i++;
	cur = head;
	while (cur != NULL && s < i)
	{
		if (cur->pos != len - 1)
			cur->pos++;
		cur = cur->next;
		s++;
	}
}

void	exit_ants(t_ants *start, int *path, int len)
{
	t_ants *cur;

	while (!is_everybody_outside(start, len - 1))
	{
		move_ants(start, path, len);
		print_ants_list(start);
		ft_printf("========\n");		
	}		
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
	ft_print1dintarr(path, len);
	ants = create_ants_list(amount);
	exit_ants(ants, path, len);
}
