#include "lem-in.h"

int		is_in_array(int num, int *arr, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (arr[i] == num)
			return (1);
	return (0);
}

void	enqueue(int num, int *arr, int len)
{
	int i;

	i = 0;
	while (i < len && arr[i] != -1)
		i++;
	arr[i] = num;
}

t_room	*find_by_id(t_room *start, int id)
{
	t_room *cur;

	cur = start;
	while (cur != NULL)
	{
		if (cur->id == id)
			return (cur);
		cur = cur->next;
	}
	return (0);
}

void	iterate_list(t_room *start)
{
	t_room	*cur;
	int		i;

	i = 0;
	cur = start;
	while (cur != NULL)
	{
		cur->id = i;
		i++;
		cur = cur->next;
	}
}

void ok(t_room *start, int *queue, int num, int len)
{
	t_room		*cur;
	t_sosed		*scur;

	cur = find_by_id(start, num);
	scur = cur->sosed;
	while (scur != NULL)
	{
		if (!is_in_array(scur->room->id, queue, len))
			enqueue(scur->room->id, queue, len);
		scur = scur->next;
	}
}

void	bfs_search(t_room *start, int len)
{
	int			i;
	int 		queue[len];
	t_room		*cur;
	t_sosed		*scur;

	i = 0;
	while (i < len)
	{
		queue[i] = -1;
		i++;
	}
	iterate_list(start);
	i = 0;	
	queue[i] = 0;
	while (i < len)
	{
		ok(start, queue, queue[i], len);
		i++;
	}
	ft_print1dintarr(queue, len);	
}
