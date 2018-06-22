#include "lem-in.h"

void print_struct_members(t_lem *item)
{
	ft_printf("name: %s\n", item->name);
	ft_printf("x: %d\n", item->x);
	ft_printf("y: %d\n", item->y);
	ft_printf("type: %d\n", item->type);
	// ft_printf("tube to: %s\n", item->tube->name);	
	ft_printf("========\n");
}

void print_list(t_lem *head)
{
	t_lem *current;

	current = head;
	while (current != NULL)
	{
		print_struct_members(current);
		current = current->next;
	}
}

t_lem	*ft_lstaddendlem(t_lem *head)
{
	t_lem *current;
	t_lem *object;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_lem));
	object = current->next;
	object->next = NULL;
	return (object);
}

void 	parse_room(t_lem *room, int type, char *line)
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

int	get_start_end(char *line, t_lem *start)
{
	t_lem *end;	
	int i;

	get_next_line(0, &line);
	get_next_line(0, &line);
	parse_room(start, 1, line);
	get_next_line(0, &line);
	get_next_line(0, &line);
	end = ft_lstaddendlem(start);
	parse_room(end, 2, line);
	return (0);
}

int two_spaces(char *line)
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

t_lem	*search(t_lem *head, char *name)
{
    t_lem *current;

	current = head;
	while (current != NULL)
	{
		if (ft_strequ(current->name, name))
        	return (current);
		current = current->next;
	}
	return (0);
}

int	parse_tubes(t_lem *head, char *line)
{
	int		i;
	char	**name;
	t_lem	*room;

	i = 0;
	while (get_next_line(0, &line))
	{
		while (line[i] && line[i] != '-')
			i++;
		if ((room = search(head, ft_strsub(line, 0, i))) == 0)
			return (0);
		room->tube = search(head, ft_strsub(line, i, ft_strlen(line)));
	}
	return (1);
}

int		main()
{
	int		i;	
	int		ants;	
	char	*line;
	t_lem	*start;	
	t_lem	*room;

	line = NULL;
	get_next_line(0, &line);
	ants = ft_atoi(line);
	if ((start = malloc(sizeof(t_lem))) == NULL)
		return (0);
	start->next = NULL;
	get_start_end(line, start);
	while (get_next_line(0, &line))
	{
		if (two_spaces(line))
		{
			room = ft_lstaddendlem(start);
			parse_room(room, 0, line);
		}
	}
	print_list(start);	
	parse_tubes(start, line);
}
