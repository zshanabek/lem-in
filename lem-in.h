#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

typedef struct	s_lem
{
	char *name;
	int x;
	int y;
	int type;
	struct s_lem *tube;	
	struct s_lem *next;
}				t_lem;

#endif
