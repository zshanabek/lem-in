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
