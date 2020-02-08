/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:13:50 by hmidoun           #+#    #+#             */
/*   Updated: 2020/02/08 17:33:23 by mvo-van-         ###   ########.fr       */
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
# define FLAG_CMT		32

typedef struct	s_typ
{
	int		ret;
	int		res;
	int		flag;
	int		tun;
}				t_typ;

typedef struct	s_point
{
	int		x;
	int		y;
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
struct	s_all_paths
{
	int				**path;
	int				size;
	int				f;
};

typedef struct s_graph	t_graph;
struct	s_graph
{
	int				nbr_f;
	int				nbr_n;
	int				**links;
	int				**tmp_path;
	int				*stack_path;
	int				nbr_curr_paths;
	int				count_curr_paths;
	t_all_paths		*curr_paths;
	long			count_next_paths;
	int				nbr_next_paths;
	t_all_paths		*next_paths;
	t_node			*tab_nodes;
};

int		cond_path_change(t_graph *graph, int k, int i_s_stack);
void	init_path(t_graph *graph);
void	bfs_conditions(t_graph *graph, int *i_link, int *tmp, int i[2]);
void	bfs(t_graph *graph);
int		set_matrix(t_graph *graph);
int		block_links(t_graph *graph);
void	fill_paths(t_graph *graph, int i[3], int *n);
int		nbr_paths(t_graph *graph);
int		get_paths(t_graph *graph);
void	free_paths(t_graph *graph, int flag);
int		free_graph(t_graph *graph);
void	ft_count(t_graph *graph);
void	ft_distrib_f(t_graph *graph);
void	output_str(t_graph graph, int i, int j);
void	output_algo(t_graph graph);
int		cp_paths(t_graph *graph);
int		cmp_paths(t_graph *graph);
int		optimal_paths(t_graph *graph);
int		ft_verif_salle_coor(int x, int y, t_node *salle);
int		ft_verif_salle_name(char *str, t_node *salle);
int		ft_hashtag(char *line);
t_node	*ft_creat_salle(t_node *salle, int flag);
int		ft_pars_salle(char *line, t_node **salle, int flag, int ***tab);
t_point	ft_pars_coord(int j, char *line);
int		ft_salle_existe(t_node *salle, char *line, int i, t_point coord);
int		ft_has_salle(char *line, t_node **salle, int flag, int ***tab);
int		ft_parsing(t_node **salle, int ***tab, t_graph *graph);
int		ft_pars_four(t_graph *graph);
int		ft_hashtag(char *line);
t_node	*ft_prev_salle(t_node *salle);
t_node	*ft_next_salle(t_node *salle);
int		ft_pars_tun(char *line, t_node **salle, int ***tab);
int		**ft_make_doubtab(t_node *salle);
int		**ft_tab_zero(int	**tab, int size, int n_node);
int		ft_free(int **tab, t_node **salle, char *line, int flag);

int		ft_link_pars(t_graph *graph, t_typ *typ, t_node **salle, char *line);
int		check_link(char *line);
int		ft_creat_tab_link(t_graph *graph, t_node *salle);
int		get_link(char *line, t_node *salle, t_graph *graph);
void	ft_free_tab(char **tab);
int		get_salle(char *line, t_node *salle);
t_point	ft_coor(t_point coor, int i, char **tab);
int		ft_room_pars(t_graph *graph, t_typ *typ, t_node **salle, char **line);
int		ft_free_line(char *line, int flag);
int		ft_atoi_positif(const char *str);
int		ft_isalldigit(char *str);

#endif
