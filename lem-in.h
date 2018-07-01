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
	int 		id;
	int			type;
	int			from;
	char		*charfrom;	
	int			is_visited;
	int			is_closed;
	int 		*way;
	t_sosed		*sosed;
	t_room		*next;
};

struct s_sosed
{
	t_room	*room;
	t_sosed	*next;
};

t_room		*parse_farm(char *line);
int			parse_tubes(t_room *head, char *line);
int			two_spaces(char *line);
void		print_struct_members(t_room *item);
void		print_list(t_room *head);
t_room		*ft_lstaddendroom(t_room *head);
t_sosed		*ft_lstaddendsosed(t_sosed *head);
int			list_length(t_room *item);
void		fill_matrix(t_room *start, int **matrix, int len);
void		algorithm(t_room *start, int len);
void		iterate_list(t_room *start, int len);
#endif
