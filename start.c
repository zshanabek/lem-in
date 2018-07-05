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
		if (cur->pos != len)
			cur->pos++;
		cur = cur->next;
		s++;
	}
}

void	print_ants_step(t_ants *head, t_room *rooms, int *path, int len)
{
	t_ants *current;

	current = head;
	while (current != NULL)
	{
		if (current->pos != -1 && current->pos != len)
			ft_printf("L%d-%s ", current->id + 1, find_by_id(rooms, path[current->pos])->name);
		current = current->next;
	}
}

void	exit_ants(t_ants *start, t_room *rooms,int *path, int len)
{
	t_ants *cur;

	while (!is_everybody_outside(start, len))
	{
		move_ants(start, path, len);
		print_ants_step(start, rooms, path, len);
		ft_putchar('\n');		
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
	ants = create_ants_list(amount);
	exit_ants(ants, rooms, path, len);
}
