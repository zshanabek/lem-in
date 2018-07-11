#include "lem-in.h"

int		is_digital(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);			
		i++;
	}
	return (1);
}

int		is_comment(char *line)
{
	if (line[0] == '#')
		return (1);
	return (0);
}

int		is_line_valid(char *line)
{
	if (ft_isempty(line) || (!is_comment(line) && !is_digital(line)))
		show_error();
	return (1);
}

int			two_spaces(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	if (count == 2 || ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		return (1);
	return (0);
}
