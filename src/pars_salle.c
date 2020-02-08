/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_salle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/02/08 17:41:57 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_salle(char *line, t_node *salle)
{
	char	**tab;
	int		i;
	t_point	coor;

	i = -1;
	if (line[0] == ' ')
		return (FLAG_ERREUR);
	tab = ft_strsplit(line, ' ');
	while (tab[++i])
		if (i == 0)
		{
			if (ft_verif_salle_name(tab[0], salle) == -1)
				salle->name = ft_strdup(tab[0]);
			else
				break ;
		}
		else if (i == 1 || i == 2)
			coor = ft_coor(coor, i, tab);
	ft_free_tab(tab);
	if (i == 3 && (ft_verif_salle_coor(coor.x, coor.y, salle) == -1))
	{
		salle->coor = coor;
		return (1);
	}
	return (FLAG_ERREUR);
}

int		ft_room_pars(t_graph *graph, t_typ *typ, t_node **salle, char **line)
{
	if (typ->ret == FLAG_START || typ->ret == FLAG_END)
	{
		if (typ->flag & typ->ret)
			return (ft_free(graph->links, salle, *line, 1));
		free(*line);
		if (get_next_line(0, line) > 0)
		{
			ft_putstr(*line);
			ft_putstr("\n");
		}
		else
			return (ft_free(graph->links, salle, *line, 1));
		typ->flag |= typ->ret;
	}
	(*salle) = ft_creat_salle((*salle), typ->ret);
	if (get_salle(*line, (*salle)) == FLAG_ERREUR)
		return (ft_free(graph->links, salle, *line, 1));
	return (1);
}
