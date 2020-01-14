/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/14 18:11:36 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

t_struct	*ft_creat_salle(t_struct *salle, char *nom, int flag, t_point coor)
{
	t_struct *new;

	if (!(new = (t_struct*)malloc(sizeof(t_struct) * 1)))
		return (NULL);
	if (salle)
	{
		salle->next = new;
		new->num = salle->num + 1;
	}
	else
		new->num = 0;
	new->prev = salle;
	new->next = NULL;
	new->nom = nom;
	new->start = 0;
	new->end = 0;
	new->coor.x = coor.x;
	new->coor.y = coor.y;
	if (flag & FLAG_START)
		new->start = 1;
	else if (flag & FLAG_END)
		new->end = 1;
	return (new);
}

t_struct	*ft_prev_salle(t_struct *salle)
{
	while (salle && salle->prev)
		salle = salle->prev;
	return (salle);
}

t_struct	*ft_next_salle(t_struct *salle)
{
	while (salle && salle->next)
		salle = salle->next;
	return (salle);
}
