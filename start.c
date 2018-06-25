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

void	search_connections(int **matrix, int *h, int len, int *visited, int *queue)
{
	int col;
	int row;

	row = queue[*h];
	col = 0;
	while(col < len)
	{
		if (matrix[row][col] == 1)
		{
			if (!is_in_array(col, visited, len) && !is_in_array(col, queue, len))
			{
				queue[*h] = col;
				(*h)++;
			}
		}
		col++;
	}
}

void	bfs_search(int **matrix, int len)
{
	int visited[len];
	int queue[len];
	int z;
	int h;	

	z = 0;
	h = 0;
	while (z < len)
	{
		visited[z] = -1;
		queue[z] = -1;
		z++;	
	}
	z = 0;	
	visited[z] = 0;
	queue[h] = 0;
	search_connections(matrix, &h, len, visited, queue);
	ft_print1dintarr(queue, len);
	ft_print1dintarr(visited, len);
}

int		main()
{
	int		len;
	char	*line;
	int		**matrix;
	t_room	*start;

	line = NULL;
	start = parse_farm(line);
	len = list_length(start);
	matrix = ft_create2dintarr(len, len);
	fill_matrix(start, matrix, len);
	ft_print2dintarr(matrix, len);
	bfs_search(matrix, len);
}
