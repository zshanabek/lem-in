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

int		bfs(t_room *start, int *queue, int num, int len)
{
	t_room		*cur;
	t_sosed		*scur;

	cur = find_by_id(start, num);
	cur->is_visited = 1;
	scur = cur->sosed;
	while (scur != NULL)
	{
		if (scur->room->type == 2)
			return (0);
		if (!is_in_array(scur->room->id, queue, len) && scur->room->is_visited != 1)
		{
			enqueue(scur->room->id, queue, len);
			ft_intcpy(scur->room->way, cur->way, len);
			enqueue(cur->id, scur->room->way, len);
		}
		scur = scur->next;
	}
	return (1);
}

void	algorithm(t_room *start, int len)
{
	int			i;
	int			queue[len];

	i = 0;
	while (i < len)
	{
		queue[i] = -1;
		i++;
	}
	i = 0;
	queue[i] = 0;
	while (i < len && bfs(start, queue, queue[i], len))
		i++;
	print_list(start, len);
}
