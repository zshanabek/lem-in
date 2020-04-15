/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:57:07 by zshanabe          #+#    #+#             */
/*   Updated: 2018/07/18 11:24:10 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void show_error(char *error_message)
{
	ft_printf("ERROR: %s\n", error_message);
	exit(1);
}

void print_path(t_room *head, int *path, int len)
{
	int i;

	i = 0;
	ft_printf("{magenta}the shortest path: ");
	while (i < len && path[i] != -1)
	{
		ft_printf("%s ", find_by_id(head, path[i])->name);
		i++;
	}
	ft_printf("{eoc}\n\n");
}

void ft_lstaddendroom(t_room **head, t_room *item)
{
	t_room *current;

	if (*head == NULL)
	{
		*head = item;
		return;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = item;
}

void ft_lstaddendsosed(t_sosed **head, t_sosed *item)
{
	t_sosed *current;

	if (*head == NULL)
	{
		*head = item;
		return;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = item;
}

t_ants *ft_lstaddendant(t_ants *head)
{
	t_ants *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_ants));
	current->next->pos = -1;
	current->next->next = NULL;
	return (current->next);
}
