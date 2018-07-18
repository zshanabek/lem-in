/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:44:12 by zshanabe          #+#    #+#             */
/*   Updated: 2018/07/18 09:51:41 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	get_ants_amount(int *amount, char *line)
{
	intmax_t temp;

	*amount = -1;
	if (get_next_line(0, &line) != 1)
		show_error("Invalid ants line");
	if (!is_comment(line) && is_digital(line))
	{
		temp = ft_atoi(line);
		if (temp <= 2147483647 && temp > 0)
			*amount = temp;
		else
			show_error("Ants amount isn't in int range");
	}
	else
		show_error("Invalid ants line");
	ft_printf("%s\n", line);
	free(line);
}

t_room	*create_room(void)
{
	t_room *room;

	room = malloc(sizeof(t_room));
	room->is_visited = 0;
	room->id = 0;
	room->sosed = NULL;
	room->next = NULL;
	return (room);
}

void	get_rooms(t_room **head, char *line)
{
	char		**arr;
	t_room		*room;
	static int	type;

	if (type != 0 && (ft_strequ(line, "##start") || ft_strequ(line, "##end")))
		show_error("No start or end room provided");
	type = (ft_strequ(line, "##start")) ? 1 : type;
	type = (ft_strequ(line, "##end")) ? 2 : type;
	if (two_spaces(line))
	{
		room = create_room();
		arr = ft_strsplit(line, ' ');
		if (!is_valid_name(*head, arr[0]) ||
		!is_digital(arr[1]) || !is_digital(arr[2]))
			show_error("Invalid room");
		room->name = ft_strdup(arr[0]);
		room->x = ft_atoi(arr[1]);
		room->y = ft_atoi(arr[2]);
		if (!unique_coordinates(*head, room->x, room->y))
			show_error("Not unique coordinates");
		ft_del2darr(arr);
		room->type = type;
		ft_lstaddendroom(head, room);
		type = 0;
	}
}

int		is_cmd_repeated(char *line)
{
	int			type;
	static int	i;
	static int	j;

	type = room_type(line);
	if (type == 1)
		i++;
	if (type == 2)
		j++;
	if (i > 1 || j > 1)
		return (0);
	return (1);
}

t_room	*parse(int *amount)
{
	int		flag;
	char	*line;
	t_room	*head;

	flag = 0;
	head = NULL;
	line = NULL;
	get_ants_amount(amount, line);
	while (get_next_line(0, &line))
	{
		if (flag == 0 && !is_cmd_repeated(line))
			show_error("Start or end doubled");
		else if (flag == 0 && (two_spaces(line) || room_type(line) != 0))
			get_rooms(&head, line);
		else if (check_link(line))
			create_links(head, &flag, line);
		else if (!is_comment(line))
			show_error("Invalid line");
		if (room_type(line) != 0 && flag == 1)
			show_error("There should be no command in links part");
		ft_printf("%s\n", line);
		free(line);
	}
	return (head);
}
