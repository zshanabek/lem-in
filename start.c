#include "lem-in.h"

void 	parse_room(t_room *room, int type, char *line)
{
	int i;

	i = 0;
	room->type = type;
	while (line[i] && line[i] != ' ')
		i++;
	room->name = ft_strsub(line, 0, i);
	i++;
	room->x = ft_atoi(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	room->y = ft_atoi(&line[i]);
}

int		get_start_end(char *line, t_room *start)
{
	int		i;
	t_room	*end;	

	get_next_line(0, &line);
	get_next_line(0, &line);
	parse_room(start, 1, line);
	get_next_line(0, &line);
	get_next_line(0, &line);
	end = ft_lstaddendroom(start);
	parse_room(end, 2, line);
	return (0);
}

int		two_spaces(char *line)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
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

t_room	*search(t_room *head, char *name)
{
    t_room *current;

	current = head;
	while (current != NULL)
	{
		if (ft_strequ(current->name, name))
        	return (current);
		current = current->next;
	}
	return (0);
}

int	create_tube(t_room *head, char *line)
{
	int			i;	
	t_room		*room;
	t_sosed		*sosed;

	i = 0;
	while (line[i] && line[i] != '-')
			i++;
	if ((room = search(head, ft_strsub(line, 0, i))) == 0)
		return (0);
	i++;
	if (search(head, ft_strsub(line, i, ft_strlen(line))) != 0)
	{
		if (room->sosed == NULL)
		{
			sosed = malloc(sizeof(t_sosed));
			sosed->next = NULL;
			room->sosed = sosed;			
		}
		else
			sosed = ft_lstaddendsosed(room->sosed);
		sosed->room = search(head, ft_strsub(line, i, ft_strlen(line)));
	}
	else
		return (0);
	return (1);
}

int		parse_tubes(t_room *head, char *line)
{
	int			i;
	t_room		*room;
	t_sosed		*sosed;

	create_tube(head, line);
	while (get_next_line(0, &line))
		create_tube(head, line);
	print_struct_members(head);	
	return (1);
}

int		main()
{
	int		i;
	int		ants;
	char	*line;
	t_room	*start;
	t_room	*room;

	line = NULL;
	get_next_line(0, &line);
	ants = ft_atoi(line);
	if ((start = malloc(sizeof(t_room))) == NULL)
		return (0);
	start->next = NULL;
	start->sosed = NULL;
	get_start_end(line, start);
	while (get_next_line(0, &line) && two_spaces(line))
	{
		room = ft_lstaddendroom(start);
		parse_room(room, 0, line);
	}
	parse_tubes(start, line);
	print_list(start);
}
