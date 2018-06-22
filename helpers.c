#include "lem-in.h"

void print_struct_members(t_room *item)
{
	t_sosed *current;

	ft_printf("name: %s\n", item->name);
	ft_printf("x: %d\n", item->x);
	ft_printf("y: %d\n", item->y);
	ft_printf("type: %d\n", item->type);
	current = item->sosed;
	ft_printf("%10s\n", "Sosedi");	
	while (current != NULL)
	{
		ft_printf("%10s\n", current->room->name);
		current = current->next;
	}
	ft_printf("========\n");
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
