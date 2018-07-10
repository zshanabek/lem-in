#include "lem-in.h"

int check_coordinates(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] != ' ')
		return (0);
	i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] != 0)
		return (0);
	return (1);
}

t_room		*insert_room(int type, char *line)
{
	int i;
	t_room *room;
	
	i = 0;
	if (!check_coordinates(line))
		show_error();
	room = malloc(sizeof(t_room));
	room->is_visited = 0;
	room->is_closed = 0;
	room->id = 0;
	room->sosed = NULL;
	room->next = NULL;
	room->type = type;
	while (line[i] && line[i] != ' ')
		i++;
	room->name = ft_strsub(line, 0, i);
	i++;
	room->x = ft_atoi(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	room->y = ft_atoi(&line[i]);
	return (room);
}

int		validate(t_room *head)
{
	t_room *cur;
	int i;

	i = 0;
	cur = head;
	while (cur != NULL)
	{
		if (cur->type == 1)
			i++;
		if (cur->type == 2)
			i++;
		cur = cur->next;
	}
	if (i == 2)
		return (1);
	else
		return (0);
}

int		is_digital(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);			
		i++;
	}
	return (1);
}

int		is_comment(char *line)
{
	if (line[0] == '#')
		return (1);
	return (0);
}

int		is_line_valid(char *line)
{
	if (ft_isempty(line) || (!is_comment(line) && !is_digital(line)))
		show_error();
	return (1);
}

int		get_ants_amount(char *line, int *ants)
{
	intmax_t temp;

	get_next_line(0, &line);
	if (is_line_valid(line))
		temp = ft_atoimax(line);
	if (temp >= 2147483647)
		show_error();
	*ants = ft_atoi(line);
	ft_printf("%s\n", line);
	return (*ants);	
}

t_room	*parse_farm(int *ants)
{
	int		type;
	char	*line;
	t_room	*head;

	type = 0;
	head = NULL;
	line = NULL;
	get_ants_amount(line, ants);
	while (get_next_line(0, &line) && !ft_strchr(line, '-'))
	{
		if (!two_spaces(line) && !is_comment(line))
			show_error();
		if (line[0] == '#' && !ft_strcmp(line, "##start"))
			type = 1;
		else if (line[0] == '#' && !ft_strcmp(line, "##end"))
			type = 2;
		ft_printf("%s\n", line);
		if (line[0] == '#')
		{
			if (type == 1 || type == 2)
				ft_strdel(&line);
			continue;
		}
		ft_lstaddendroom(&head, insert_room(type, line));
		type = 0;
		ft_strdel(&line);
	}
	if (!validate(head) || !parse_tubes(head, line))
		show_error();
	return (head);
}
