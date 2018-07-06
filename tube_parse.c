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

int		create_tube(t_room *head, char *line)
{
	int			i;
	t_room		*room;
	t_sosed		*sosed;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	if ((room = search(head, ft_strsub(line, 0, i))) == 0)
		return (0);
	i++;
	if (search(head, ft_strsub(line, i, ft_strlen(line))) != 0)
	{
		if (room->sosed == NULL)
		{
			sosed = malloc(sizeof(t_sosed));
			sosed->next = NULL;
			room->sosed = sosed;
		}
		else
			sosed = ft_lstaddendsosed(room->sosed);
		sosed->room = search(head, ft_strsub(line, i, ft_strlen(line)));
	}
	else
		return (0);
	return (1);
}

int		parse_tubes(t_room *head, char *line)
{
	if (!create_tube(head, line))
	{
		return (0);
	}
	while (get_next_line(0, &line))
	{
		ft_printf("%s\n", line);
		if (!create_tube(head, line))
			return (0);
	}
	return (1);
}
