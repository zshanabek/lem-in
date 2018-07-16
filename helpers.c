#include "lem-in.h"

int		is_digital(char *line)
{
	int i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);			
		i++;
	}
	return (1);
}

int		is_comment(char *line)
{
	if (line[0] == '#')
		return (1);
	return (0);
}

int 	room_type(char *line)
{
	if (ft_strequ(line, "##start"))
		return (1);
	else if (ft_strequ(line, "##end"))
		return (2);
	return (0);
}

t_room	*get_end(t_room *head)
{
	t_room *cur;

	cur = head;
	while (cur != NULL)
	{
		if (cur->type == 2)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t_room	*get_start(t_room *head)
{
	t_room *cur;

	cur = head;
	while (cur != NULL)
	{
		if (cur->type == 1)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

int		is_everybody_outside(t_ants *start, int end)
{
	t_ants *cur;

	cur = start;
	while (cur != NULL)
	{
		if (cur->pos != end)
			return (0);
		cur = cur->next;
	}
	return (1);
}