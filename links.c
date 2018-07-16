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

void	create_link(t_room *room1, t_room *room2)
{
	t_sosed *sosed;

	sosed = malloc(sizeof(t_sosed));
	sosed->next = NULL;
	sosed->room = room2;
	ft_lstaddendsosed(&room1->sosed, sosed);	
}

void	create_links(t_room *h, char *line)
{
	int			i;
	char		*temp;
	t_room		*room2;
	t_room		*room1;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	temp = ft_strsub(line, 0, i);
	if ((room1 = search(h, temp)) == 0)
	{
		free(temp);
		show_error();
	}
	free(temp);
	temp = ft_strsub(line, ++i, ft_strlen(line));
	if ((room2 = search(h, temp)) == 0)
	{
		free(temp);
		show_error();
	}
	free(temp);	
	create_link(room1, room2);
	create_link(room2, room1);
}