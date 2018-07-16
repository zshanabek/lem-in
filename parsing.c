#include "lem-in.h"

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

int			check_room(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (line[i] != ' ')
		return (0);
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

void	get_ants_amount(int *amount, int *fline, char *line)
{
	intmax_t temp;

	if (!is_comment(line) && is_digital(line))
	{
		temp = ft_atoi(line);
		if (temp <= 2147483647 && temp > 0)
			*amount = temp;
		else
			show_error();
	}
	else
		show_error();
}

t_room *create_room()
{
	t_room *room;

	room = malloc(sizeof(t_room));
	room->is_visited = 0;
	room->id = 0;
	room->sosed = NULL;
	room->next = NULL;
	return (room);
}

void	take_coordinates(t_room *room, int i, char *line)
{
	i++;
	room->x = ft_atoi(&line[i]);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	i++;
	room->y = ft_atoi(&line[i]);
}

void	get_rooms(t_room **head, char *line)
{
	int		i;
	char	*name;
	t_room	*room;
	static int	type;

	type = (ft_strequ(line, "##start")) ? 1 : type;
	type = (ft_strequ(line, "##end")) ? 2 : type;
	if (check_room(line))
	{
		room = create_room();
		i = 0;
		while (line[i] && line[i] != ' ')
			i++;
		name = ft_strsub(line, 0, i);
		if (!is_valid_name(*head, line))
			show_error();
		room->name = name;
		take_coordinates(room, i, line);
		room->type = type;
		ft_lstaddendroom(head, room);
		type = 0;
	}
}

int	check_link(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '-' && line[i] != ' ')
		i++;
	if (line[i] != '-')
		return (0);
	i++;
	while (line[i] && line[i] != '-' && line[i] != ' ')
		i++;
	if (line[i] != 0)
		return (0);
	return (1);
}

int			is_cmd_repeated(char *line)
{
	int			type;	
	static int	i;
	static int	j;

	type = 0;
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
	int 	fline;
	int		flag;	
	char	*line;
	t_room	*head;

	*amount = -1;
	flag = 0;
	head = NULL;
	while (get_next_line(0, &line))
	{
		if (!is_cmd_repeated(line))
			show_error();
		if (*amount == -1)
			get_ants_amount(amount, &fline, line);
		else if (flag == 0 && (check_room(line) || room_type(line) != 0))
			get_rooms(&head, line);
		else if (check_link(line))
			create_links(head, &flag, line);
		else if (!is_comment(line))
			show_error();
		ft_printf("%s\n", line);
		free(line);
	}
	return (head);
}