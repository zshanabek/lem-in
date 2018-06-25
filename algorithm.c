#include "lem-in.h"

void	fill_matrix(t_room *start, int **matrix, int len)
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
				matrix[scur->room->id][cur->id] = 1;
				scur = scur->next;
			}	
		}
  		cur = cur->next;
  	}
}