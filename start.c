#include "lem-in.h"

int		main()
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	ft_printf("%s\n", line);
}
