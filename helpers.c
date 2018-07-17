/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:58:11 by zshanabe          #+#    #+#             */
/*   Updated: 2018/07/17 20:58:37 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		is_digital(char *line)
{
	int i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int		room_type(char *line)
{
	if (ft_strstr(line, "##start"))
	{
		if (ft_strequ(line, "##start"))
			return (1);
		else
			show_error();
	}
	else if (ft_strstr(line, "##end"))
	{
		if (ft_strequ(line, "##end"))
			return (2);
		else
			show_error();
	}
	return (0);
}

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

t_room	*get_start(t_room *head)
{
	t_room *cur;

	cur = head;
	while (cur != NULL)
	{
		if (cur->type == 1)
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
