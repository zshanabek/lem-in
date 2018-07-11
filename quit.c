#include "lem-in.h"

t_room	*get_end(t_room *head)
{
	t_room *cur;

	cur = head;
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

void	move_ants(t_ants *head, int len)
{
	int			s;
	t_ants		*cur;
	static int	i;
	
	i++;
	s = 0;
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
	int		ok;	
	t_ants	*current;

	ok = 0;
	current = head;
	while (current != NULL)
	{
		if (current->pos != 0 && current->pos != len && current->pos != -1)
		{
			if (path[current->pos] != -1)
			{
				ft_printf("{cyan}L%d-{eoc}{yellow}%s{eoc} ", current->id, 
				find_by_id(rooms, path[current->pos])->name);
				ok = 1;				
			}
		}
		current = current->next;
	}
	if (ok)
		ft_putchar('\n');		
}

int		one_step(int *path, int len)
{
	int		i;	
	int		count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (path[i] != -1)
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}

void	exit_in_1_step(t_ants *head, char *end_name)
{
	t_ants *cur;

	cur = head;
	while (cur)
	{
		ft_printf("{cyan}L%d-{eoc}{yellow}%s{eoc} ", cur->id, end_name);
		cur = cur->next;
	}
	ft_putchar('\n');
}

void	exit_ants(t_ants *start, t_room *rooms, int len)
{
	t_room	*end;
	int		*path;

	end = get_end(rooms);
	path = end->way;
	print_path(rooms, path, len);
	if (one_step(path, len))
		exit_in_1_step(start, end->name);
	else
	{
		while (!is_everybody_outside(start, len))
		{
			move_ants(start, len);
			print_ants_step(start, rooms, path, len);
		}
	}
}