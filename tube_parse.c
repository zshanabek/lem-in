#include "lem-in.h"

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

void	create_tube(t_room *head, char *line)
{
	int			i;
	t_room		*room;
	t_room 		*room2;
	t_sosed		*sosed;
	char 		*temp;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	if ((room = search(head, (temp = ft_strsub(line, 0, i)))) == 0)
	{
		free(temp);
		show_error();
	}
	free(temp);
	if ((room2 = search(head, (temp = ft_strsub(line, ++i, ft_strlen(line))))) != 0)
	{
		sosed = malloc(sizeof(t_sosed));
		sosed->next = NULL;
		sosed->room = room2;
		ft_lstaddendsosed(&room->sosed, sosed);
		free(temp);
	}
	else
	{
		free(temp);
		show_error();
	}
}

void	parse_tubes(t_room *head, char *line)
{
	create_tube(head, line);
	ft_printf("%s\n", line);	
	while (get_next_line(0, &line))
	{
		if (is_comment(line))
		{
			ft_printf("%s\n", line);
			continue;
		}
		create_tube(head, line);
		ft_printf("%s\n", line);
		free(line);	
	}
}
