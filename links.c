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

int			validate_se(t_room *head)
{
	int		i;
	t_room	*cur;

	i = 0;
	cur = head;
	while (cur != NULL)
	{
		if (cur->type == 1 || cur->type == 2)
			i++;
		cur = cur->next;
	}
	if (i != 2)
		return (0);
	return (1);
}

void	create_links(t_room *h, int *flag, char *line)
{
	int			i;
	t_room		*room2;
	t_room		*room1;
	char 		**arr;

	i = 0;
	if (*flag == 0 && !validate_se(h))
		show_error();
	*flag = 1;
	arr = ft_strsplit(line, '-');
	if ((room1 = search(h, arr[0])) == 0)
		show_error();
	if ((room2 = search(h, arr[1])) == 0)
		show_error();
	create_link(room1, room2);
	create_link(room2, room1);
}