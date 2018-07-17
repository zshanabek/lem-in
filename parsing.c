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

void	get_ants_amount(int *amount, char *line)
{
	intmax_t temp;

	*amount = -1;
	if (get_next_line(0, &line) != 1)
		show_error();
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
	ft_printf("%s\n", line);
	free(line);
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

void	get_rooms(t_room **head, char *line)
{
	char 	**arr;
	t_room	*room;
	static int	type;

	if (type != 0 && (ft_strequ(line, "##start") || ft_strequ(line, "##end")))
		show_error();
	type = (ft_strequ(line, "##start")) ? 1 : type;
	type = (ft_strequ(line, "##end")) ? 2 : type;
	if (two_spaces(line))
	{
		room = create_room();
		arr = ft_strsplit(line, ' ');
		if (!is_valid_name(*head, arr[0]))
			show_error();
		if (!is_digital(arr[1]) || !is_digital(arr[2]))
			show_error();
		room->name = arr[0];
		room->x = ft_atoi(arr[1]);
		room->y = ft_atoi(arr[2]);
		if (!unique_coordinates(*head, room->x, room->y))
			show_error();	
		room->type = type;
		ft_lstaddendroom(head, room);
		type = 0;
	}
}

int	check_link(char *line)
{
	int i;

	i = 0;
	if (line[0] == '#')
		return (0);
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
			show_error();
		else if (flag == 0 && (two_spaces(line) || room_type(line) != 0))
			get_rooms(&head, line);
		else if (check_link(line))
			create_links(head, &flag, line);
		else if (!is_comment(line))
			show_error();
		if (room_type(line) != 0 && flag == 1)
			show_error();
		ft_printf("%s\n", line);
		free(line);
	}
	return (head);
}