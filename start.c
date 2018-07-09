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

int		main(void)
{
	int		len;
	int 	amount;
	t_ants	*ants;
	t_room	*rooms;

	rooms = parse_farm(&amount);
	len = list_length(rooms);	
	iterate_list(rooms, len);
	algorithm(rooms, len);
	ants = create_ants_list(amount);
	ft_putchar('\n');
	exit_ants(ants, rooms, len);
	ft_roomlstdel(&rooms);
	// system("leaks lem-in");
}
