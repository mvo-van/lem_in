/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:13:50 by hmidoun           #+#    #+#             */
/*   Updated: 2020/01/17 14:19:02 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

# define FLAG_START 	1
# define FLAG_END		2
# define DEF_SALLE		4
# define DEF_TUN		8
# define FLAG_ERREUR	16

typedef struct	s_point
{
	int	x;
	int y;
}				t_point;

typedef struct	s_node
{
	struct s_node	*prev;
	char			*name;
	int				n_node;
	int				start;
	int				end;
	t_point			coor;
	struct s_node	*next;
}				t_node;

typedef struct s_all_paths	t_all_paths;
struct	s_all_paths	//list of all paths
{
	int				*path;
	int				size;
	int				f;
};

typedef struct s_graph	t_graph;
struct	s_graph
{
	int				nbr_f;//fourmie
	int				nbr_n;//nodes
	int				**links;//links matrix

	int				**tmp_path;//current path for bfs
	int				*stack_path;//stack for bfs

	int				nbr_curr_paths;
	t_all_paths		*curr_paths;
	int				nbr_next_paths;
	t_all_paths		*next_paths;

	t_node			*tab_nodes;
};

int			cond_path_change(t_graph *graph, int k, int i_s_stack);
void		init_path(t_graph *graph);
void		bfs_conditions(t_graph *graph, int *i_link, int *tmp, int i[2]);
void		bfs(t_graph *graph);


int			set_matrix(t_graph *graph,  t_node **salle);


void		block_links(t_graph *graph);
void		fill_paths(t_graph *graph, int i[3], int *n);
int			nbr_paths(t_graph *graph);
int			get_paths(t_graph *graph);

void		free_paths(t_graph *paths, int flag);
int			free_graph(t_graph *graph);

int			ft_count(t_graph graph);
void		ft_distrib_f(t_graph *graph, int count);


int			ft_hashtag(char *line);
t_node		*ft_creat_salle(t_node *salle,char *name,int flag, t_point coor);
int			ft_pars_salle(char *line, t_node **salle, int flag, int ***tab);
t_point 	ft_pars_coord(int j, char *line);
int			ft_salle_existe(t_node *salle, char *line, int i, t_point coord);
int			ft_has_salle(char *line, t_node **salle, int flag, int ***tab);
int			ft_parsing(t_node **salle, int ***tab, int *nb_four);
int			ft_pars_four(char *line, int *nb_four);
int			ft_hashtag(char *line);
t_node		*ft_prev_salle(t_node *salle);
t_node		*ft_next_salle(t_node *salle);
int         ft_pars_tun(char *line, t_node **salle, int ***tab);
int			**ft_make_doubtab(t_node *salle);
int			**ft_tab_zero(int	**tab, int size, int n_node);
int			ft_free(int ***tab, t_node **salle);


#endif
