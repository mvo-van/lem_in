/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/14 14:03:38 by mvo-van-         ###   ########.fr       */
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

typedef struct s_point
{
	int	x;
	int y;
}t_point;

typedef struct s_struct
{
	struct s_struct	*prev;
	char			*nom;
	int				num;
	int				start;
	int				end;
	t_point			coor;
	struct s_struct *next;
} t_struct;




int			ft_hashtag(char *line);
t_struct	*ft_creat_salle(t_struct *salle,char *nom,int flag, t_point coor);
int			ft_pars_salle(char *line, t_struct **salle, int flag, int ***tab);
t_point 	ft_pars_coord(int j, char *line);
int			ft_salle_existe(t_struct *salle, char *line, int i, t_point coord);
int			ft_has_salle(char *line, t_struct **salle, int flag, int ***tab);
int			ft_parsing(t_struct **salle, int ***tab, int *nb_four);
int			ft_pars_four(char *line, int *nb_four);
int			ft_hashtag(char *line);
t_struct	*ft_prev_salle(t_struct *salle);
t_struct	*ft_next_salle(t_struct *salle);
int         ft_pars_tun(char *line, t_struct **salle, int ***tab);
int		**ft_make_doubtab(t_struct *salle);
int		**ft_tab_zero(int	**tab,int size);
int	ft_free(int ***tab, t_struct **salle);

#endif
