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

void	move_ants(t_ants *head, int *path)
{

}

int	is_everybody_outside(int *array, int endid)
{

}

void	exit_ants(int *path, int len, int endid)
{
	t_ants *cur;
	int array[len];
	int i;

	i = 0;
	while (i < len)
	{
		array[i] = 0;
		i++;
	}
	while(!is_everybody_outside(array, endid))
		move_ants(path, len);
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
	exit_ants(path, len, end->id);
}
