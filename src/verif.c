/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/02/10 19:07:13 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_atoi_positif(const char *str)
{
	int		i;
	int		result;
	long	number;

	number = 0;
	result = -1;
	i = 0;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		number = number * 10 + *(str + i) - '0';
		if (number > 2147483647)
			return (-1);
		i++;
	}
	if (*(str + i))
		return (-1);
	result = (int)number;
	return (result);
}

int		ft_verif_salle_name(char *str, t_node *salle)
{
	salle = ft_next_salle(salle);
	while (salle)
	{
		if (salle->name && !(ft_strcmp(salle->name, str)))
			return (salle->n_node);
		salle = salle->prev;
	}
	return (-1);
}

int		ft_hashtag(char *line)
{
	if (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start"))
			return (FLAG_START);
		if (!ft_strcmp(line, "##end"))
			return (FLAG_END);
		else
			return (FLAG_CMT);
	}
	return (0);
}

int		ft_verif_salle_coor(int x, int y, t_node *salle)
{
	salle = ft_next_salle(salle);
	if (x == -1 || y == -1)
		return (0);
	while (salle)
	{
		if (salle->coor.x == x && salle->coor.y == y)
			return (salle->n_node);
		salle = salle->prev;
	}
	return (-1);
}

int		ft_isalldigit(char *str)
{
	int		i;

	i = 0;
	while (str + i && *(str + i) >= '0' && *(str + i) <= '9')
		i++;
	if (*(str + i))
		return (0);
	return (1);
}
