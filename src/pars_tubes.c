/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/02/10 18:04:53 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_link(char *line)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	if (line[0] == '#')
		return (0);
	while (line[j])
	{
		if (line[j] == '-')
		{
			count++;
			if (count > 1)
				return (2);
		}
		j++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		get_link(char *line, t_node *salle, t_graph *graph)
{
	char	**tab;
	int		i;
	int		link_1;
	int		link_2;

	i = -1;
	if (line[0] == ' ')
		return (FLAG_ERREUR);
	tab = ft_strsplit(line, '-');
	while (tab[++i])
		if (i == 0)
			link_1 = ft_verif_salle_name(tab[0], salle);
		else if (i == 1)
			link_2 = ft_verif_salle_name(tab[1], salle);
	ft_free_tab(tab);
	if (link_1 == -1 || link_2 == -1 || i != 2)
		return (FLAG_ERREUR);
	else
	{
		graph->links[link_1][link_2] = 1;
		graph->links[link_2][link_1] = 1;
	}
	if (i == 2)
		return (1);
	return (FLAG_ERREUR);
}

int		**ft_tab_zero(int **tab, int size, int n_node)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = n_node;
			j++;
		}
		i++;
	}
	return (tab);
}

int		**ft_make_doubtab(t_node *salle)
{
	int		**tab;
	int		i;
	int		j;

	salle = ft_next_salle(salle);
	if (!salle)
		return (NULL);
	i = salle->n_node;
	if (!(tab = (int**)malloc(sizeof(int*) * (i + 1))))
		return (NULL);
	j = 0;
	while (j <= i)
	{
		if (!(tab[j] = (int*)malloc(sizeof(int) * (i + 1))))
		{
			while (j-- > 0)
				free(tab[j]);
			free(tab);
			return (NULL);
		}
		j++;
	}
	tab[j] = NULL;
	return (ft_tab_zero(tab, i + 1, salle->n_node + 1));
}

int		ft_link_pars(t_graph *graph, t_typ *typ, t_node **salle, char *line)
{
	if (!((typ->flag & FLAG_START) && (typ->flag & FLAG_END)) ||
		(check_link(line) != 1))
		return (ft_free(graph->links, salle, line, 1));
	else if (typ->tun == 0)
		ft_creat_tab_link(graph, (*salle));
	typ->tun = 1;
	if (typ->ret == 0 && (get_link(line, (*salle), graph) == FLAG_ERREUR))
		return (ft_free(graph->links, salle, line, 1));
	return (1);
}
