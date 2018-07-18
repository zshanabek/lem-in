/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:59:04 by zshanabe          #+#    #+#             */
/*   Updated: 2018/07/18 12:30:57 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_valid_name(t_room *head, char *name)
{
	t_room *cur;

	if (name[0] == 'L' || name[0] == '#')
		return (0);
	if (ft_strchr(name, '-') != 0)
		return (0);
	cur = head;
	while (cur != NULL)
	{
		if (ft_strequ(cur->name, name))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int		uni_coord(t_room *head, t_room *elem, intmax_t x, intmax_t y)
{
	t_room *cur;

	if (x <= 2147483647 && x >= -2147483648 && y <= 2147483647 &&
	y >= -2147483648)
	{
		elem->x = x;
		elem->y = y;
	}
	else
		show_error("Room coordinates aren't in integer range");
	cur = head;
	while (cur != NULL)
	{
		if (cur->x == x && cur->y == y)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int		two_spaces(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int		is_comment(char *line)
{
	if (line[0] == '#')
		return (1);
	return (0);
}
