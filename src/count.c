/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:19:07 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/21 06:03:19 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_count(t_graph *graph)
{
	int		i;
	int		j;
	int		total;
	int		nb_f;

	j = 1;
	nb_f = graph->nbr_f;
	graph->count_next_paths = -1;
	i = graph->nbr_next_paths;
	total = 0;
	while (--i >= 0 && (graph->count_next_paths == -1 || graph->count_next_paths > graph->next_paths[i].size))
	{
		total += graph->next_paths[i].size;
		graph->count_next_paths = ((nb_f + total - 1) / j);
		j++;
	}
}

void	ft_distrib_f(t_graph *graph)
{
	int		i;
	int		nb_f;

	nb_f = (*graph).nbr_f;
	i = (*graph).nbr_curr_paths;
	while (--i >= 0 && nb_f)
	{
		if ((graph->count_curr_paths  - (*graph).curr_paths[i].size + 1) >= nb_f)
			(*graph).curr_paths[i].f = nb_f;
		else
			(*graph).curr_paths[i].f = graph->count_curr_paths  - (*graph).curr_paths[i].size + 1;
		nb_f -= (*graph).curr_paths[i].f;
	}
	while (i >= 0)
	{
		(*graph).curr_paths[i].f = 0;
		i--;
	}
}
