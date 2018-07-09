#include "lem-in.h"

t_room		*insert_room(int type, char *line)
{
	int i;
	t_room *room;
	
	i = 0;
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
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int		is_line_valid(char *line)
{
	if (ft_isempty(line))
		exit(1);
	if (!is_comment(line) && !is_digital(line))
		exit(1);
	return (1);
}

int		get_ants_amount(char *line, int *ants)
{
	get_next_line(0, &line);
	if (is_line_valid(line))
		*ants = ft_atoi(line);
	return (*ants);	
}

t_room	*parse_farm(int *ants)
{
	int		id;
	int		type;	
	char	*line;
	t_room	*head;

	id = 0;
	type = 0;
	head = NULL;
	line = NULL;
	get_ants_amount(line, ants);
	ft_printf("{yellow}ants: %d\n{eoc}", *ants);
	while (get_next_line(0, &line) && !ft_strchr(line, '-'))
	{
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
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (head);
}
