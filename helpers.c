#include "lem-in.h"

void		print_struct_members(t_room *item)
{
	t_sosed *current;

	ft_printf("id: %d\n", item->id);
	ft_printf("name: %s\n", item->name);
	ft_printf("type: %d\n", item->type);
	ft_printf("x: %d\n", item->x);	
	ft_printf("y: %d\n", item->y);						
	current = item->sosed;
	if (item->sosed != NULL)
		ft_printf("Sosedi: ")	;
	while (current != NULL)
	{
		ft_printf("%s ", current->room->name);
		current = current->next;
	}
	ft_printf("\n===============\n");
}

void	show_error(void)
{
	ft_printf("ERROR\n");
	exit(1);
}

void		print_list(t_room *head)
{
	t_room *current;

	current = head;
	while (current != NULL)
	{
		print_struct_members(current);
		current = current->next;
	}
}

void		print_ants_list(t_ants *head)
{
	t_ants *current;

	current = head;
	while (current != NULL)
	{
		ft_printf("id: %d\n", current->id);
		ft_printf("pos: %d\n", current->pos);		
		current = current->next;
	}
}

void	print_path(t_room *head, int *path, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (path[i] != -1)
			ft_printf("%s ", find_by_id(head, path[i])->name);
		else
			ft_printf("-1 ");
		i++;
	}
	ft_putchar('\n');
}

void	ft_lstaddendroom(t_room **head, t_room *item)
{
	t_room	*current;

	if (*head == NULL)
	{
		*head = item;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = item;
}

void	ft_lstaddendsosed(t_sosed **head, t_sosed *item)
{
	t_sosed *current;
	if (*head == NULL)
	{
		*head = item;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = item;
}


t_ants	*ft_lstaddendant(t_ants *head)
{
	t_ants	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_ants));
	current->next->pos = -1;
	current->next->next = NULL;
	return (current->next);
}

t_ants *create_ants_list(int amount)
{
	int		i;	
	t_ants	*start;
	t_ants	*ant;

	i = 2;
	start = malloc(sizeof(t_ants *));
	start->id = 1;
	start->pos = -1;
	start->next = NULL;
	while (i < amount + 1)
	{
		ant = ft_lstaddendant(start);
		ant->id = i;
		i++;
	}
	return (start);
}

int			two_spaces(char *line)
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
	if (count == 2 || ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		return (1);
	return (0);
}

int			list_length(t_room *item)
{
	int		size;
	t_room	*cur;

	size = 0;
	cur = item;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}

void	iterate_list(t_room *start, int len)
{
	int		i;
	int		j;
	int		*way;
	t_room	*cur;

	i = 0;
	cur = start;
	while (cur != NULL)
	{
		j = 0;
		way = malloc(sizeof(int) * len);
		while (j < len)
		{
			way[j] = -1;
			j++;
		}
		cur->way = way;
		cur->id = i;
		cur = cur->next;
		i++;
	}
}
