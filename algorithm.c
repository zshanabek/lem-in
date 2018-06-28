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

void	add_to_queue(int *arr, int num, int len)
{
	int i;

	i = 0;
	while (i < len && arr[i] != -1)
		i++;
	arr[i] = num;
}

int		search_connections(int **matrix, int num, int len, int *visited, int *queue)
{
	int		col;
	int		bar;

	col = 0;
	bar = 0;
	while (col < len)
	{
		if (matrix[num][col] == 1)
		{
			if (!is_in_array(col, visited, len) && !is_in_array(col, queue, len))
			{
				add_to_queue(queue, col, len);
				bar = 1;
			}
		}
		col++;
	}
	return (bar);
}

void	bfs_search(int **matrix, int len)
{
	int visited[len];
	int queue[len];
	int z;
	int q;	

	z = 0;
	q = 0;	
	while (z < len)
	{
		visited[z] = -1;
		queue[z] = -1;
		z++;
	}
	z = 0;
	visited[z] = 0;
	queue[z] = 0;
	while (q < len)
	{
		if (search_connections(matrix, queue[q], len, visited, queue))
		{
			visited[z] = queue[q];
			z++;
		}
		ft_printf("que: %d\n", queue[q]);
		ft_print1dintarr(queue, len);
		ft_print1dintarr(visited, len);
		ft_printf("===============\n");
		q++;
	}

}