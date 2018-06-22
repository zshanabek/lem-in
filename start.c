#include "lem-in.h"

void print_struct_members(t_lem *item)
{
	ft_printf("se: %d\n", item->start_end);
	ft_printf("name: %s\n", item->name);
	ft_printf("x: %d\n", item->x);
	ft_printf("y: %d\n", item->y);
	ft_printf("========\n");
}

t_lem	*ft_lstaddendlem(t_lem *head)
{
	t_lem *current;
	t_lem *object;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_lem));
	object = current->next;
	object->next = NULL;
	return (object);
}

int	get_start_end(char *line, t_lem *start)
{
	t_lem *end;	
	int i;

	get_next_line(0, &line);
	get_next_line(0, &line);
	start->start_end = 1;
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	start->name = ft_strsub(line, 0, i);
	start->x = ft_atoi(&line[2]);
	start->y = ft_atoi(&line[5]);
	get_next_line(0, &line);	
	get_next_line(0, &line);
	print_struct_members(start);		
	end = ft_lstaddendlem(start);
	end->start_end = 2;
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	end->name = ft_strsub(line, 0, i);
	end->x = ft_atoi(&line[2]);
	end->y = ft_atoi(&line[5]);
	print_struct_members(end);
	return (0);
}

int two_spaces(char *line)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int		main()
{
	int		i;	
	int		ants;	
	char	*line;
	t_lem	*start;	
	t_lem	*room;

	line = NULL;
	get_next_line(0, &line);
	ants = ft_atoi(line);
	if ((start = malloc(sizeof(t_lem))) == NULL)
		return (0);
	start->next = NULL;
	get_start_end(line, start);
	while (get_next_line(0, &line))
	{
		if (two_spaces(line))
		{
			room = ft_lstaddendlem(start);
			room->start_end = 0;
			i = 0;
			while (line[i] && line[i] != ' ')
				i++;
			room->name = ft_strsub(line, 0, i);
			room->x = ft_atoi(&line[2]);
			room->y = ft_atoi(&line[5]);
			print_struct_members(room);	
		}
	}
}
