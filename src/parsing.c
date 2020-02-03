/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/02/03 14:06:40 by mvo-van-         ###   ########.fr       */
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
	result = (int)number;
	return (result);
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
	else if (!(*line))
		return (FLAG_ERREUR);
	else
	{
		j = -1;
		while (line[++j])
			if (!ft_isdigit(line[j]))
				return (FLAG_ERREUR);
		*nb_four = ft_atoi(line);
		if (*nb_four <= 0)
			return (FLAG_ERREUR);
		return (DEF_SALLE);
	}
}

int		ft_free(int **tab, t_node **salle, int flag)
{
	int i;
	t_node *save;

	*salle = ft_next_salle(*salle);
	i = ((*salle) ? ((*salle)->n_node) : -1);
	//int j = 0;
	if (tab)
	{
		while (i >= 0)
		{
			free(tab[i]);
			i--;
		}
		free(tab);
	}
	while (*salle)
	{
		save = (*salle)->prev;
		if ((*salle)->name)
			free((*salle)->name);
		free(*salle);
		*salle = save;
	}
	*salle = NULL;
	if (flag)
		write(1, "ERREUR\n", 7);
	return (1);
}
#include <stdio.h>
int		ft_parsing(t_node **salle, int ***tab, int *nb_four)
{
	char	*line;
	int		flag;

	*salle = NULL;
	*tab = NULL;
	flag = 0;
	//fd = open("test", O_RDONLY);
	while (!(flag & FLAG_ERREUR) && get_next_line(0, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
		if (flag == 0)
			flag |= ft_pars_four(line, nb_four);
		else if (flag & DEF_SALLE && !(flag & DEF_TUN)){
			flag |= ft_pars_salle(line, salle, 0, tab);
		}
		if (flag & DEF_SALLE && flag & DEF_TUN)
		{
			flag |= ft_pars_tun(line, salle, tab);
			if (!(flag & FLAG_END) || !(flag & FLAG_START))
				flag |= FLAG_ERREUR;
		}
		free(line);
	}
	if ((flag & FLAG_ERREUR) || !(*salle) || !(*tab))
		return (ft_free(*tab, salle, 1));
	return (0);
}
