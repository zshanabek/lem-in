#include "lem-in.h"

void	insert_room(t_room *room, int type, char *line)
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

t_room	*identify_room(t_room *head, int *flag, int type, char *line)
{
	t_room *item;

	if (two_spaces(line))
	{
		if (*flag == 1)
		{
			*flag = 0;
			head = malloc(sizeof(t_room));
			head->next = NULL;
			head->sosed = NULL;
			head->is_visited = 0;
			head->is_closed = 0;
			head->id = 0;
			insert_room(head, type, line);
			return (head);
		}
		else
		{
			item = ft_lstaddendroom(head);
			insert_room(item, type, line);
		}
	}
	return (0);
}

t_room	*parse_farm(int *ants)
{
	int		id;
	int		flag;
	char	*line;
	t_room	*head;
	int		type;

	line = NULL;
	id = 0;
	type = 0;	
	flag = 1;
	get_next_line(0, &line);
	ft_printf("%s\n", line);
	*ants = ft_atoi(line);
	while (get_next_line(0, &line) && !ft_strstr(line, "-"))
	{
		if (line[0] == '#' && line[1] != '#')
		{
			ft_printf("%s\n", line);			
			get_next_line(0, &line);
		}
		else if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		{
			ft_printf("%s\n", line);			
			type = (!ft_strcmp(line, "##start")) ? 1 : 2;
			get_next_line(0, &line);
			(flag == 1) ? head = identify_room(head, &flag, type, line) :
			identify_room(head, &flag, type, line);
		}
		else
			(flag == 1) ? head = identify_room(head, &flag, type, line) :
			identify_room(head, &flag, type, line);
		type = 0;
		ft_printf("%s\n", line);						
	}
	if (parse_tubes(head, line) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (head);
}
