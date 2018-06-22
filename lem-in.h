#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

typedef struct s_sosed t_sosed;
typedef struct s_room t_room;

struct	s_room
{
	char		*name;
	int			x;
	int			y;
	int			type;
	t_sosed		*sosed;	
	t_room		*next;
};

struct s_sosed
{
	t_room	*room;
	t_sosed	*next;
};

int			two_spaces(char *line);
void		print_struct_members(t_room *item);
void		print_list(t_room *head);
t_room		*ft_lstaddendroom(t_room *head);
t_sosed		*ft_lstaddendsosed(t_sosed *head);

#endif
