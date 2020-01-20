/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_salle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/20 13:45:30 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_has_salle(char *line, t_node **salle, int flag, int ***tab)
{
	static int	start = 0;
	int			i;
	int			j;

	i = ft_hashtag(line);
	if (!(*line) || (line[0] == '#' && flag))
		return (FLAG_ERREUR);
	if (i & FLAG_START || i & FLAG_END)
	{
		if (start & i || flag)
			return (FLAG_ERREUR);
		start |= (i & FLAG_START ? FLAG_START : FLAG_END);
		if (get_next_line(0, &line))
		{
			ft_putstr(line);
			ft_putchar('\n');
			j = ft_pars_salle(line, salle, i, tab);
			free(line);
			return (j + i);
		}
		else
			return (FLAG_ERREUR);
	}
	return (0);
}

int			ft_salle_existe(t_node *salle, char *line, int i, t_point coord)
{
	int		j;

	salle = ft_next_salle(salle);
	while (salle)
	{
		j = 0;
		if (coord.x == salle->coor.x && coord.y == salle->coor.y)
			return (1);
		while (salle->name[j] && line[j] && salle->name[j] == line[j] && j < i)
			j++;
		if (!salle->name[j] && line[j] == ' ')
			return (1);
		salle = salle->prev;
	}
	return (0);
}

t_point		ft_pars_coord(int j, char *line)
{
	t_point		coord;
	int			i;

	i = 1;
	coord.x = -1;
	coord.y = -1;
	while (line[j + i] && line[j + i] != ' ')
	{
		if (!ft_isdigit(line[j + i]))
			return (coord);
		i++;
	}
	coord.x = ft_atoi(line + j);
	j += i;
	i = 1;
	while (line[j + i])
	{
		if (!ft_isdigit(line[j + i]))
			return (coord);
		i++;
	}
	if (i == 1)
		return (coord);
	coord.y = ft_atoi(line + j);
	return (coord);
}

int			ft_pars_salle(char *line, t_node **salle, int flag, int ***tab)
{
	int			j;
	t_point		coord;
	char		*name;

	if (line[0] == '#' || !(*line))
		return (ft_has_salle(line, salle, flag, tab));
	else
	{
		j = 0;
		while (line[j] && line[j] != ' ')
			j++;
		if (line[j] != ' ')
		{
			if (!(*tab = ft_make_doubtab(*salle)))
				return (FLAG_ERREUR);
			return (DEF_TUN);
		}
		coord = ft_pars_coord(j, line);
		if (coord.x == -1 || coord.y == -1 ||
			ft_salle_existe(*salle, line, j, coord))
			return (FLAG_ERREUR);
		name = ft_memcpy(ft_memalloc(j + 1), line, j);
		*(salle) = ft_creat_salle(*salle, name, flag, coord);
		return (DEF_SALLE);
	}
}
