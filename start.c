#include "lem-in.h"

int		main()
{
	int		i;
	int		ants;
	char	*line;
	t_room	*start;
	t_room	*room;

	line = NULL;
	start = parse_farm(line);
	print_list(start);
}
