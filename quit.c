#include "lem-in.h"

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
	int			s;
	t_ants		*cur;
	static int	i;

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