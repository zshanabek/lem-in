#include "lem-in.h"

int		main()
{
	int		len;
	int		**matrix;
	char	*line;	
	t_room	*start;

	line = NULL;
	start = parse_farm(line);
	print_list(start);
	len = list_length(start);
	matrix = ft_create2dintarr(len, len);
	fill_matrix(start, matrix, len);
	ft_print2dintarr(matrix, len);
	bfs_search(matrix, len);
}
