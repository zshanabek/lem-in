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

void	iterate_list(t_room *elem)
{
	int		j;
	static int i;
	int 	*way;

	j = 0;
	way = malloc(sizeof(int) * 30);
	while (j < 30)
	{
		way[j] = -1;
		j++;
	}
	elem->way = way;
	elem->id = i;
	i++;
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

void	ft_roomlstiter(t_room *lst, void (*f)(t_room *elem))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}

int		main(void)
{
	int			len;
	int			amount;
	t_ants		*ants;
	t_room		*rooms;
	int			*path;
	
	rooms = parse(&amount);
	len = list_length(rooms);
	ft_roomlstiter(rooms, iterate_list);
	// print_list(rooms);
	algorithm(rooms, len);
	path = get_end(rooms)->way;
	ft_putchar('\n');
	print_path(rooms, path, len);
	ants = create_ants_list(amount);
	exit_ants(ants, rooms, len);
	ft_roomlstdel(&rooms);
}
