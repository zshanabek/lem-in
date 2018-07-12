#include "lem-in.h"

static void		ft_roomlstdel(t_room **head)
{
	t_room		*cur;	
	t_room		*temp;
	t_sosed		*scur;
	t_sosed		*stemp;	

	if (!head)
		return ;
	cur = *head;
	while (cur)
	{
		temp = cur->next;
		free(cur->way);
		free(cur->name);
		scur = cur->sosed;
		while (scur)
		{
			stemp = scur->next;
			free(scur);
			scur = stemp;
		}
		free(cur);
		cur = temp;
	}
	*head = NULL;
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

t_ants *create_ants_list(intmax_t amount)
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

int		main(void)
{
	int			len;
	intmax_t	amount;
	t_ants		*ants;
	t_room		*rooms;

	rooms = parse_farm(&amount);
	if (!validate_se(rooms))
		show_error();
	len = list_length(rooms);	
	iterate_list(rooms, len);
	// print_list(rooms);
	algorithm(rooms, len);
	ants = create_ants_list(amount);
	ft_putchar('\n');
	exit_ants(ants, rooms, len);
	ft_roomlstdel(&rooms);
	// system("leaks lem-in");
}
