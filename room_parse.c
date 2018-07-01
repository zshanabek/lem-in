#include "lem-in.h"

void 	insert_room(t_room *room, int type, int *id, char *line)
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
	(*id)++;
}

t_room	*identify_room(t_room *head, int *flag, int *id, int type, char *line)
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
			insert_room(head, type, id, line);
			return (head);
		}
		else
		{
			item = ft_lstaddendroom(head);
			insert_room(item, type, id, line);
		}
	}
	return (0);
}

t_room	*parse_farm(char *line)
{
	int		id;	
	int		flag;	
	t_room	*head;

	id = 0;
	flag = 1;
	get_next_line(0, &line);
	while (get_next_line(0, &line) && !ft_strstr(line, "-"))
	{
		if (ft_strstr(line, "##start"))
		{
			get_next_line(0, &line);
			if (flag == 1)
				head = identify_room(head, &flag, &id, 1, line);
			else
				identify_room(head, &flag, &id, 1, line);
		}
		else if (ft_strstr(line, "##end"))
		{
			get_next_line(0, &line);
			if (flag == 1)
				head = identify_room(head, &flag, &id, 2, line);
			else
				identify_room(head, &flag, &id, 2, line);
		}
		else
		{
			if (flag == 1)
				head = identify_room(head, &flag, &id, 0, line);
			else
				identify_room(head, &flag, &id, 0, line);
		}
	}
	if (parse_tubes(head, line) == 0)
	{
		ft_printf("Error");
		exit(1);
	}
	return (head);
}
