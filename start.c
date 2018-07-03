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

void	increment(t_room *head)
{
	t_cur *cur;

	if (cur != NULL)
	{
		cur = cur->next;
	}
}

void	move_ants(t_ants *head, int *path)
{
	t_ants *cur;

	cur = head;
	while (cur != NULL)
	{
		
		cur = cur->next;
	}
}

void	exit_ants(t_ants *start, int *path, int endid)
{
	t_ants *cur;

	while(!is_everybody_outside(start, endid))
		move_ants(start, path);
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
	exit_ants(ants, path, end->id);
	is_everybody_outside(ants, end->id);
}
