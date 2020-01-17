/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:19:07 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/17 11:22:32 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_count(t_graph graph)
{
	int		i;
	int		j;
	int		total;
	int		count;
	int		nb_f;

	j = 1;
	nb_f = graph.nbr_f;
	count = -1;
	i = graph.nbr_next_paths;
	total = 0;
	while (--i >= 0 && (count == -1 || count > graph.next_paths[i].size))
	{
		total += graph.next_paths[i].size;
		count = ((nb_f + total - 1) / j);
		j++;
	}
	return (count);
}

void	ft_distrib_f(t_graph *graph, int count)
{
	int		i;
	int		nb_f;

	nb_f = (*graph).nbr_f;
	i = (*graph).nbr_next_paths;
	while (--i >= 0 && nb_f)
	{
		if ((count - (*graph).next_paths[i].size + 1) >= nb_f)
			(*graph).next_paths[i].f = nb_f;
		else
			(*graph).next_paths[i].f = count - (*graph).next_paths[i].size + 1;
		nb_f -= (*graph).next_paths[i].f;
	}
	while (i >= 0)
	{
		(*graph).next_paths[i].f = 0;
		i--;
	}
}
