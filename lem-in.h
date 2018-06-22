#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

typedef struct	s_lem
{
	char *name;
	int x;
	int y;
	int start_end;
	struct s_lem *next;
}				t_lem;

#endif
