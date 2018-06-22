#include "lem-in.h"

void 	insert_room(t_room *head, int type, int *init, char *line)
{
	int i;
	t_room *room;

	i = 0;
	if (*init == 1)
	{
		room = malloc(sizeof(t_room));
		room->next = NULL;
		room->sosed = NULL;
		*init = 0;		
	}
	else
		room = ft_lstaddendroom(head);
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

int		parse_rooms(char *line)
{
	int		flag;
	t_room	*room;
	t_room	*start;

	flag = 1;
	while (get_next_line(0, &line) && !ft_strchr(line, '-'))
	{	
		if (ft_strstr(line, "##start"))
		{
			get_next_line(0, &line);
			insert_room(room, 1, &flag, line);				
		}
		else if (ft_strstr(line, "##end"))
		{
			get_next_line(0, &line);
			insert_room(room, 2, &flag, line);			
		}
		else
		{
			room = ft_lstaddendroom(start);
			insert_room(room, 0, &flag, line);
		}
	}
	print_list(start);
	return (1);
}

int		parse_tubes(t_room *head, char *line)
{
	int			i;
	t_room		*room;
	t_sosed		*sosed;

	if (!create_tube(head, line))
		return (0);
	while (get_next_line(0, &line))
	{
		if (!create_tube(head, line))
			return (0);
	}
	return (1);
}