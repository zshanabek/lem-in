#include "lem-in.h"

int		list_length(t_room *item)
{
	int		size;	
	t_room	*cur;

	size = 0;
	cur = item;  	
  	while (cur != NULL)
  	{
  	  size++;
  	  cur = cur->next;
  	}
  	return (size);
}

void	iterate_matrix(t_room *start, int **matrix, int len)
{
	int i;
	int j;
	t_room	*cur;
	t_sosed	*scur;	

	i = -1;
	while (++i < len && (j = -1))
		while (++j < len)
			matrix[i][j] = 0;

	cur = start;
	while (cur != NULL)
  	{
		if (cur->sosed != NULL)
		{
			scur = cur->sosed;
			while (scur != NULL)
			{
				matrix[cur->id][scur->room->id] = 1;
				scur = scur->next;
			}	
		}
  		cur = cur->next;
  	}
	ft_print2dintarr(matrix, len);
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
	iterate_matrix(start, matrix, len);
}
