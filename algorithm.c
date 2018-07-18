/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:17:08 by zshanabe          #+#    #+#             */
/*   Updated: 2018/07/18 10:40:53 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_in_array(int num, int *arr, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (arr[i] == num)
			return (1);
	return (0);
}

void	enqueue(int num, int *arr, int len)
{
	int i;

	i = 0;
	while (i < len && arr[i] != -1)
		i++;
	arr[i] = num;
}

t_room	*find_by_id(t_room *start, int id)
{
	t_room *cur;

	cur = start;
	while (cur != NULL)
	{
		if (cur->id == id)
			return (cur);
		cur = cur->next;
	}
	return (0);
}

int		bfs(t_room *start, int *queue, int num, int len)
{
	t_room		*cur;
	t_sosed		*scur;

	cur = find_by_id(start, num);
	if (num == -1)
		return (1);
	cur->is_visited = 1;
	scur = cur->sosed;
	while (scur != NULL)
	{
		if (!is_in_array(scur->room->id, queue, len) &&
		scur->room->is_visited != 1)
		{
			enqueue(scur->room->id, queue, len);
			ft_intcpy(scur->room->way, cur->way, len);
			enqueue(cur->id, scur->room->way, len);
		}
		if (scur->room->type == 2)
		{
			enqueue(scur->room->id, scur->room->way, len);
			return (1);
		}
		scur = scur->next;
	}
	return (0);
}

void	algorithm(t_room *head, int len)
{
	int			i;
	int			queue[len];
	t_room		*start;

	i = 0;
	while (i < len)
	{
		queue[i] = -1;
		i++;
	}
	i = 0;
	start = get_start(head);
	queue[i] = start->id;
	while (i < len && !bfs(head, queue, queue[i], len))
		i++;
	if (get_end(head)->way[0] != start->id)
		show_error("There is no available path");
}
