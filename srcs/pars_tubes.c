/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/14 18:01:55 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int			**ft_tab_zero(int **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

int			**ft_make_doubtab(t_struct *salle)
{
	int		**tab;
	int		i;
	int		j;

	salle = ft_next_salle(salle);
	if (!salle)
		return (NULL);
	i = salle->num;
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
	return (ft_tab_zero(tab, i + 1));
}

int			ft_has_tun(char *line)
{
	int i;

	i = ft_hashtag(line);
	if (i & FLAG_START || i & FLAG_END)
		return (FLAG_ERREUR);
	return (0);
}

t_point		ft_salle_existe_tun(t_struct *salle, char *line, int i)
{
	t_point		coord;
	int			j;

	coord.x = -1;
	coord.y = -1;
	salle = ft_next_salle(salle);
	while (salle)
	{
		j = 0;
		while (salle->nom[j] && line[j] && salle->nom[j] == line[j] && j < i)
			j++;
		if (!salle->nom[j] && line[j] == '-')
			coord.x = salle->num;
		j = 1;
		while (salle->nom[j - 1] && line[j + i] &&
			salle->nom[j - 1] == line[j + i])
			j++;
		if ((!salle->nom[j - 1]) && (!line[j + i]))
			coord.y = salle->num;
		salle = salle->prev;
	}
	return (coord);
}

int			ft_pars_tun(char *line, t_struct **salle, int ***tab)
{
	int			j;
	t_point		coord;

	if (line[0] == '#')
		return (ft_has_tun(line));
	else
	{
		j = 0;
		while (line[j] && line[j] != '-')
		{
			if (line[j] == ' ' || line[j] == '\t')
				return (FLAG_ERREUR);
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
