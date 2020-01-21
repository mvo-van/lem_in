/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/21 17:14:30 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			**ft_tab_zero(int **tab, int size, int n_node)
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

int			**ft_make_doubtab(t_node *salle)
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

int			ft_has_tun(char *line)
{
	int i;

	i = ft_hashtag(line);
	if (i & FLAG_START || i & FLAG_END)
		return (FLAG_ERREUR);
	return (0);
}
#include <stdio.h>
t_point		ft_salle_existe_tun(t_node *salle, char *line, int i)
{
	t_point		coord;
	int			j;

	coord.x = -1;
	coord.y = -1;
	salle = ft_next_salle(salle);
	while (salle)
	{
		j = 0;
		while (salle->name[j] && line[j] && salle->name[j] == line[j] && j < i)
			j++;
		if (!salle->name[j] && line[j] == '-')
			coord.x = salle->n_node;
		j = 1;
		while (salle->name[j - 1] && line[j + i] &&
			salle->name[j - 1] == line[j + i])
			j++;
		if ((!salle->name[j - 1]) && (!line[j + i]))
			coord.y = salle->n_node;
		salle = salle->prev;
	}
	return (coord);
}
#include <stdio.h>
int			ft_pars_tun(char *line, t_node **salle, int ***tab)
{
	int			j;
	t_point		coord;

	if (line[0] == '#'){
		return (ft_has_tun(line));}
	else
	{
		j = 0;
		while (line[j] && line[j] != '-')
		{
			if (line[j] == ' ' || line[j] == '\t')
			{
				return (FLAG_ERREUR);
			}
			j++;
		}
		coord = ft_salle_existe_tun(*salle, line, j);
		if (coord.x == -1 || coord.y == -1)
			return (FLAG_ERREUR);
		(*tab)[coord.x][coord.y] = 1;
		(*tab)[coord.y][coord.x] = 1;
		return (0);
	}
}
