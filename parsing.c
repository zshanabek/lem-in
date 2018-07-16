#include "lem-in.h"

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

	if (is_line_valid(line))
	{
		temp = ft_atoi(line);
		if (temp <= 2147483647 && temp > 0)
			*amount = temp;
		else
			show_error();
	}
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

t_room		*insert_room(char *line)
{
	int		i;
	char	*name;
	t_room	*room;

	room = create_room();	
	i = 0;	
	while (line[i] && line[i] != ' ')
		i++;
	name = ft_strsub(line, 0, i);
	room->name = name;
	take_coordinates(room, i, line);
	return (room);
}

void get_rooms(t_room **head, char *line)
{
	t_room *room;

	if (check_room(line))
	{
		room = insert_room(line);
		room->type = 0;
		ft_lstaddendroom(head, room);
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


t_room	*parse(int *amount)
{
	int 	fline;	
	char	*line;
	t_room	*head;

	*amount = -1;
	line = NULL;
	head = NULL;
	while (get_next_line(0, &line))
	{
		if (*amount == -1)
			get_ants_amount(amount, &fline, line);
		get_rooms(&head, line);
		if (check_link(line))
			create_links(head, line);
		free(line);
	}
	return (head);
}