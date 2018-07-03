#include "lem-in.h"

int		*get_path(t_room *start)
{
	t_room *cur;

	cur = start;
	while (cur != NULL)
	{
		if (cur->type == 2)
			return (cur->way);
		cur = cur->next;
	}
	return (0);
}

void	exit_ants(int *path)
{
	
}

t_ants	*ft_lstaddendant(t_ants *head)
{
	t_ants	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_ants));
	current->next->pos = 0;
	current->next->next = NULL;
	return (current->next);
}

t_ants *create_ants_list(int amount)
{
	int		i;	
	t_ants	*start;
	t_ants	*ant;

	i = 1;
	start = malloc(sizeof(t_ants *));
	start->id = 0;
	start->pos = 0;
	start->next = NULL;
	while (i < amount)
	{
		ant = ft_lstaddendant(start);
		ant->id = i;
		i++;
	}
	return (start);
}

int		main(void)
{
	int		len;
	int		*path;
	char	*line;
	t_room	*start;
	t_ants	*ants_lst;
	int 	ants;

	line = NULL;
	start = parse_farm(line, &ants);
	len = list_length(start);
	iterate_list(start, len);
	algorithm(start, len);
	path = get_path(start);
	ft_print1dintarr(path, len);
	ants_lst = create_ants_list(ants);
	print_ants_list(ants_lst);	
}
