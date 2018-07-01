#include "lem-in.h"

int		main()
{
	int		len; 
	char	*line;	
	t_room	*start;

	line = NULL;
	start = parse_farm(line);
	len = list_length(start);
	iterate_list(start, len);
	algorithm(start, len);
}
