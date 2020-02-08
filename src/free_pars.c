/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/02/08 17:29:03 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

int		ft_free_line(char *line, int flag)
{
	if (line)
		free(line);
	if (flag & FLAG_ERREUR)
		write(1, "ERROR\n", 7);
	return (FLAG_ERREUR);
}

void	ft_free_room(t_node **salle)
{
	t_node *save;

	while (*salle)
	{
		save = (*salle)->prev;
		if ((*salle)->name)
			free((*salle)->name);
		free(*salle);
		*salle = save;
	}
}

int		ft_free(int **tab, t_node **salle, char *line, int flag)
{
	int i;

	*salle = ft_next_salle(*salle);
	i = ((*salle) ? ((*salle)->n_node) : -1);
	if (tab)
	{
		while (i >= 0)
		{
			free(tab[i]);
			i--;
		}
		free(tab);
	}
	ft_free_room(salle);
	*salle = NULL;
	if (line)
		free(line);
	if (flag)
		write(1, "ERROR\n", 7);
	return (FLAG_ERREUR);
}
