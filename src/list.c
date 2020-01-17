/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/17 13:22:15 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*ft_creat_end_start(t_node *salle, t_node *new, int flag)
{
	t_node	*save;

	salle = ft_prev_salle(salle);
	new->prev = NULL;
	if (flag & FLAG_END)
	{
		if (salle && salle->start)
		{
			save = salle->next;
			salle->next = new;
			new->prev = salle;
			salle = save;
		}
		new->end = 1;
		new->n_node = 1;
	}
	else
	{
		new->start = 1;
		new->n_node = 0;
	}
	if (salle)
		salle->prev = new;
	new->next = salle;
	return (ft_next_salle(new));
}

t_node	*ft_creat_salle(t_node *salle, char *name, int flag, t_point coor)
{
	t_node *new;

	if (!(new = (t_node*)malloc(sizeof(t_node) * 1)))
		return (NULL);
	new->name = name;
	new->start = 0;
	new->end = 0;
	new->coor.x = coor.x;
	new->coor.y = coor.y;
	if (flag & FLAG_END || flag & FLAG_START)
		return (ft_creat_end_start(salle, new, flag));
	new->n_node = 2;
	if (salle)
	{
		salle->next = new;
		if (salle->n_node >= 2)
			new->n_node = salle->n_node + 1;
	}
	new->prev = salle;
	new->next = NULL;
	return (new);
}

t_node	*ft_prev_salle(t_node *salle)
{
	while (salle && salle->prev)
		salle = salle->prev;
	return (salle);
}

t_node	*ft_next_salle(t_node *salle)
{
	while (salle && salle->next)
		salle = salle->next;
	return (salle);
}
