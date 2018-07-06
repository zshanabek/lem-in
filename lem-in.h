#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

typedef struct s_sosed t_sosed;
typedef struct s_room t_room;
typedef struct s_ants t_ants;

struct	s_room
{
	char		*name;
	int			x;
	int			y;
	int 		id;
	int			type;
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

struct s_ants
{
	int		id;
	int		pos;
	t_ants	*next;
};
t_room		*find_by_id(t_room *start, int id);
t_room		*parse_farm(int *ants);
int			parse_tubes(t_room *head, char *line);
int			two_spaces(char *line);
void		print_struct_members(t_room *item, int len);
void		print_list(t_room *head, int len);
void		print_ants_list(t_ants *head);
t_room		*ft_lstaddendroom(t_room *head);
t_sosed		*ft_lstaddendsosed(t_sosed *head);
t_ants 		*create_ants_list(int amount);
int			list_length(t_room *item);
void		fill_matrix(t_room *start, int **matrix, int len);
void		algorithm(t_room *start, int len);
void		iterate_list(t_room *start, int len);
void		exit_ants(t_ants *start, t_room *rooms,int *path, int len);
void		print_path(t_room *head, int *path, int len);
#endif
