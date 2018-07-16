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
t_room		*parse(int *amount);
void		print_struct_members(t_room *item);
void		print_list(t_room *head);
void		print_ants_list(t_ants *head);
void		ft_lstaddendroom(t_room **head, t_room *item);
void		ft_lstaddendsosed(t_sosed **head, t_sosed *item);
void		algorithm(t_room *start, int len);
void		iterate_list(t_room *start, int len);
void		exit_ants(t_ants *start, t_room *rooms, int len);
void		print_path(t_room *head, int *path, int len);
int			validate_se(t_room *head);
void		show_error(void);
int			is_comment(char *line);
t_ants		*ft_lstaddendant(t_ants *head);
int			is_everybody_outside(t_ants *start, int end);
t_room		*get_end(t_room *head);
t_room		*get_start(t_room *head);
void		create_links(t_room *h, int *flag, char *line);
int 		room_type(char *line);
int			check_link(char *line);
int		is_digital(char *line);
#endif
