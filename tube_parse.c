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

t_sosed	*ft_allocate_mem(t_room *r)
{
	t_sosed *sosed;

	sosed = malloc(sizeof(t_sosed));
	sosed->next = NULL;
	sosed->room = r;
	return (sosed);
}

void	create_tube(t_room *h, char *line)
{
	int			i;
	char		*temp;
	t_room		*r;
	t_room		*room;
	t_sosed		*sosed;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	temp = ft_strsub(line, 0, i);
	if ((room = search(h, temp)) == 0)
	{
		free(temp);
		show_error();
	}
	free(temp);
	temp = ft_strsub(line, ++i, ft_strlen(line));
	if ((r = search(h, temp)) == 0)
	{
		free(temp);
		show_error();
	}
	sosed = ft_allocate_mem(r);
	ft_lstaddendsosed(&room->sosed, sosed);
	free(temp);
}

void	parse_tubes(t_room *head, char *line)
{
	create_tube(head, line);
	ft_printf("%s\n", line);
	free(line);	
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
