/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 17:26:53 by zshanabe          #+#    #+#             */
/*   Updated: 2018/07/06 18:03:51 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				ft_printf("L%d-%s ", current->id, 
				find_by_id(rooms, path[current->pos])->name);
			ok = 1;
		}
		current = current->next;
	}
	if (ok)
		ft_putchar('\n');		
}

void	exit_ants(t_ants *start, t_room *rooms, int len)
{
	t_ants *cur;
	t_room	*end;
	int		*path;

	end = get_end(rooms);
	path = end->way;	
	while (!is_everybody_outside(start, len))
	{
		move_ants(start, path, len);
		print_ants_step(start, rooms, path, len);
	}
}