#include "lem-in.h"

void print_struct_members(t_room *item)
{
	t_sosed *current;

	ft_printf("%d)\n", item->id);
	ft_printf("name: %s\n", item->name);
	ft_printf("type: %d\n", item->type);
	// ft_printf("x: %d\n", item->x);
	// ft_printf("y: %d\n", item->y);
	current = item->sosed;
	if (item->sosed != NULL)
		ft_printf("%s\n", "Sosedi:");
	while (current != NULL)
	{
		ft_printf("%7s\n", current->room->name);
		current = current->next;
	}
	ft_printf("===========\n");
}

void print_list(t_room *head)
{
	t_room *current;

	current = head;
	while (current != NULL)
	{
		print_struct_members(current);
		current = current->next;
	}
}

t_room		*ft_lstaddendroom(t_room *head)
{
	t_room *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_room));
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

int		two_spaces(char *line)
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

int		list_length(t_room *item)
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

void	fill_matrix(t_room *start, int **matrix, int len)
{
	int i;
	int j;
	t_room	*cur;
	t_sosed	*scur;	

	i = -1;
	while (++i < len && (j = -1))
		while (++j < len)
			matrix[i][j] = 0;
	cur = start;
	while (cur != NULL)
  	{
		if (cur->sosed != NULL)
		{
			scur = cur->sosed;
			while (scur != NULL)
			{
				matrix[cur->id][scur->room->id] = 1;
				matrix[scur->room->id][cur->id] = 1;
				scur = scur->next;
			}
		}
  		cur = cur->next;
  	}
}
