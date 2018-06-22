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

int	create_tube(t_room *head, char *line)
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

int		main()
{
	int		i;
	int		ants;
	char	*line;
	t_room	*start;
	t_room	*room;

	line = NULL;
	get_next_line(0, &line);
	ants = ft_atoi(line);
	parse_rooms(line);
	if (!parse_tubes(start, line))
	{
		ft_printf("Error!\n");
		exit(1);
	}
	print_list(start);
}
