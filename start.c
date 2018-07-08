#include "lem-in.h"

void	ft_roomlstdel(t_room **head)
{
	t_room *temp;
	t_sosed *current;
	t_sosed *stemp;	

	if (!head)
		return ;
	while (*head != NULL)
	{
		temp = (*head)->next;
		current = (*head)->sosed;
		ft_strdel(&((*head)->name));
		free((*head)->way);		
		while (current != NULL)
		{
			stemp = current->next;
			free(current);
			current = stemp;
		}
		ft_memdel((void **)head);
		*head = temp;
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
	system("leaks lem-in");
}
