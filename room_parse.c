#include "lem-in.h"

int			check_coordinates(char *line)
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

int			unique_coordinates(t_room *head, int x, int y)
{
	t_room *cur;

	cur = head;
	while (cur != NULL)
	{
		if (cur->x == x && cur->y == y)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int			validate_room_name(t_room *head, char *name)
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

t_room *create_room(int type, char *name)
{
	t_room *room;

	room = malloc(sizeof(t_room));
	room->is_visited = 0;
	room->id = 0;
	room->sosed = NULL;
	room->next = NULL;
	room->type = type;
	room->name = name;	
	return (room);
}

void	take_coordinates(t_room *room, int i, char *line)
{
	int		k;
	
	i++;
	k = i;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] != ' ')
		show_error();
	room->x = ft_atoi(&line[k]);
	i++;	
	k = i;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] != 0)
		show_error();
	room->y = ft_atoi(&line[k]);
}

t_room		*insert_room(t_room *head, int type, char *line)
{
	int		i;
	char	*name;
	t_room	*room;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	name = ft_strsub(line, 0, i);
	if (!validate_room_name(head, name))
		show_error();
	room = create_room(type, name);
	take_coordinates(room, i, line);
	if (!unique_coordinates(head, room->x, room->y))
		show_error();
	return (room);
}

int			validate(int type)
{
	static int i;
	static int j;

	if (type == 1)
		i++;
	if (type == 2)
		j++;
	if (i > 1 || j > 1)
		return (0);
	ft_printf("ok: %d %d\n", i, j);
	return (1);
}

int			validate_se(t_room *head)
{
	int		i;
	t_room	*cur;

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
	return (0);
}

int			get_ants_amount(char *line, intmax_t *ants)
{
	intmax_t temp;

	if (get_next_line(0, &line) != 1)
		show_error();
	if (is_line_valid(line))
		temp = ft_atoimax(line);
	if (temp >= 2147483647 || temp <= 0)
		show_error();
	*ants = ft_atoi(line);
	ft_printf("%s\n", line);
	free(line);
	return (*ants);
}

t_room		*parse_farm(intmax_t *ants)
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
		type = (ft_strequ(line, "##start")) ? 1 : type;
		type = (ft_strequ(line, "##end")) ? 2 : type;
		if (!validate(type))
			show_error();		
		if (type == 1 || type == 2)
		{
			ft_printf("%s\n", line);
			get_next_line(0, &line);		
			if (!two_spaces(line))
				show_error();
		}
		if (two_spaces(line))
		{
			ft_lstaddendroom(&head, insert_room(head, type, line));
			type = 0;
		}
		if (!two_spaces(line) && !is_comment(line))
			show_error();
		ft_printf("%s\n", line);
		free(line);
	}
	if (!validate_se(head) || (line == NULL))
		show_error();
	parse_tubes(head, line);
	return (head);
}
