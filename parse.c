#include "lem-in.h"

void 	insert_room(t_room *room, int type,  char *line)
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


void	parse_rooms(char *line)
{
	t_room *head;
	t_room *item;
	int flag;
	flag = 1;

	while (get_next_line(0, &line) && !ft_strstr(line, "-"))
	{
		if (two_spaces(line))
		{
			if (flag == 1)
			{
				head = malloc(sizeof(t_room));
				head->next = NULL;
				head->sosed = NULL;
				insert_room(head, 0, line);
				flag = 0;
			}
			else
			{
				item = ft_lstaddendroom(head);
				insert_room(item, 0, line);
			}
		}
	}
	print_list(head);
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