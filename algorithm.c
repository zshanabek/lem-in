#include "lem-in.h"

int		is_in_array(char *name, int *arr, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (ft_strequ(arr[i], name))
			return (1);
	return (0);
}

void	add_to_queue(int *arr, int num, int len)
{
	int i;

	i = 0;
	while (i < len && arr[i] != -1)
		i++;
	arr[i] = num;
}

void	search_connection(t_room *start, int *visited, int *queue, int len)
{

}

void	bfs_search(t_room *start, int len)
{
	int			i;
	int			queue[len];
	t_room		*cur;
	t_sosed		*scur;

	i = 0;
	while (i < len)
	{
		queue[i] = -1;
		i++;
	}
	
}
