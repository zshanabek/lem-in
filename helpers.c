#include "lem-in.h"

void		print_struct_members(t_room *item, int len)
{
	t_sosed *current;

	ft_printf("id: %d\n", item->id);
	ft_printf("name: %s\n", item->name);
	ft_printf("type: %d\n", item->type);	
	ft_printf("way: ");
	ft_print1dintarr(item->way, len);
	current = item->sosed;
	if (item->sosed != NULL)
		ft_printf("Sosedi: ");
	while (current != NULL)
	{
		ft_printf("%s ", current->room->name);
		current = current->next;
	}
	ft_printf("\n==========================\n");
}

void		print_list(t_room *head, int len)
{
	t_room *current;

	current = head;
	while (current != NULL)
	{
		print_struct_members(current, len);
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

t_room		*ft_lstaddendroom(t_room *head)
{
	t_room	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_room));
	current->next->is_visited = 0;
	current->next->is_closed = 0;
	current->next->id = 0;
	current->next->sosed = NULL;
	current->next->next = NULL;
	return (current->next);
}

t_sosed		*ft_lstaddendsosed(t_sosed *head)
{
	t_sosed *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_sosed));
	current->next->next = NULL;
	return (current->next);
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
	if (count == 2)
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
