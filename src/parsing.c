/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/17 13:59:11 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_hashtag(char *line)
{
	if (!(ft_strcmp(line, "##start")))
		return (FLAG_START);
	else if (!(ft_strcmp(line, "##end")))
		return (FLAG_END);
	return (0);
}

int		ft_pars_four(char *line, int *nb_four)
{
	int		i;
	int		j;

	if (line[0] == '#')
	{
		i = ft_hashtag(line);
		if (i & FLAG_START || i & FLAG_END)
			return (FLAG_ERREUR);
		return (0);
	}
	else if (!line)
		return (FLAG_ERREUR);
	else
	{
		j = 0;
		while (line[j])
		{
			if (!ft_isdigit(line[j]))
				return (FLAG_ERREUR);
			j++;
		}
		*nb_four = ft_atoi(line);
		return (DEF_SALLE);
	}
}

int		ft_free(int ***tab, t_node **salle)
{
	int i;

	*salle = ft_next_salle(*salle);
	i = ((*salle) ? ((*salle)->n_node) : -1);
	if (*tab)
	{
		while (i >= 0)
		{
			free((*tab)[i]);
			i--;
		}
		free(*tab);
	}
	*tab = NULL;
	while (*salle)
	{
		if ((*salle)->name)
			free((*salle)->name);
		free(*salle);
		*salle = (*salle)->prev;
	}
	*salle = NULL;
	return (1);
}

int		ft_parsing(t_node **salle, int ***tab, int *nb_four)
{
	char	*line;
	int		flag;

	*salle = NULL;
	*tab = NULL;
	flag = 0;
	while (get_next_line(0, &line) && !(flag & FLAG_ERREUR))
	{
		ft_putstr(line);
		ft_putchar('\n');
		if (flag == 0)
			flag |= ft_pars_four(line, nb_four);
		else if (flag & DEF_SALLE && !(flag & DEF_TUN))
			flag |= ft_pars_salle(line, salle, 0, tab);
		if (flag & DEF_SALLE && flag & DEF_TUN)
		{
			flag |= ft_pars_tun(line, salle, tab);
			if (!(flag & FLAG_END) || !(flag & FLAG_START))
				flag |= FLAG_ERREUR;
		}
		free(line);
	}
	if (flag & FLAG_ERREUR)
		return (ft_free(tab, salle));
	return (0);
}
