/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/02/10 18:01:00 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_pars_four(t_graph *graph)
{
	char	*line;
	int		ret;

	while (get_next_line(0, &line) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		ret = ft_hashtag(line);
		if (ret == FLAG_START || ret == FLAG_END)
			return (ft_free_line(line, FLAG_ERREUR));
		if (ret != FLAG_CMT)
		{
			if ((graph->nbr_f = ft_atoi_positif(line)) <= 0)
				return (ft_free_line(line, FLAG_ERREUR));
			free(line);
			return (1);
		}
		free(line);
	}
	write(1, "ERROR\n", 7);
	return (FLAG_ERREUR);
}

t_point	ft_coor(t_point coor, int i, char **tab)
{
	if (i == 1)
	{
		coor.x = ft_atoi(tab[i]);
		if (!ft_isalldigit(tab[i]))
			coor.x = -1;
	}
	else if (i == 2)
	{
		coor.y = ft_atoi(tab[2]);
		if (!ft_isalldigit(tab[2]))
			coor.y = -1;
	}
	return (coor);
}

int		ft_creat_tab_link(t_graph *graph, t_node *salle)
{
	int		i;
	int		j;

	salle = ft_next_salle(salle);
	if (!salle)
		return (FLAG_ERREUR);
	i = salle->n_node;
	if (!(graph->links = (int**)malloc(sizeof(int*) * (i + 1))))
		return (FLAG_ERREUR);
	j = 0;
	while (j <= i)
	{
		if (!(graph->links[j] = (int*)malloc(sizeof(int) * (i + 1))))
		{
			while (j-- > 0)
				free(graph->links[j]);
			free(graph->links);
			graph->links = NULL;
			return (FLAG_ERREUR);
		}
		j++;
	}
	ft_tab_zero(graph->links, i + 1, salle->n_node + 1);
	return (i);
}

int		ft_pars_suite(t_graph *graph, t_node **salle)
{
	t_typ	typ;
	char	*line;

	typ.res = 0;
	typ.flag = 0;
	typ.tun = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		typ.ret = ft_hashtag(line);
		typ.res = ((typ.res != 0) ? typ.res : check_link(line));
		if (typ.ret != FLAG_CMT && !(typ.res))
		{
			if (ft_room_pars(graph, &typ, salle, &line) == FLAG_ERREUR)
				return (FLAG_ERREUR);
		}
		else if (typ.ret != FLAG_CMT && typ.res)
			if (ft_link_pars(graph, &typ, salle, line) == FLAG_ERREUR)
				return (FLAG_ERREUR);
		free(line);
	}
	if (!(graph->links))
		return (ft_free(NULL, salle, NULL, 1));
	return (1);
}

int		ft_parsing(t_node **salle, int ***tab, t_graph *graph)
{
	int		flag;

	*salle = NULL;
	*tab = NULL;
	flag = 0;
	if (ft_pars_four(graph) != FLAG_ERREUR)
	{
		if (ft_pars_suite(graph, salle) == FLAG_ERREUR)
			return (FLAG_ERREUR);
	}
	else
		return (FLAG_ERREUR);
	return (0);
}
