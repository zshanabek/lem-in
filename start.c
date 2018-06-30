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
	bfs_search(start, len);
}
