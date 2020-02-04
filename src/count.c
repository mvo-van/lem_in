/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:19:07 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/02/04 19:13:18 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		sort(t_all_paths *paths, int *t, int size)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i <  size)
		t[i] = i;
	i = size;
	while (--i >= 0)
	{
		j = size ;
		while (--j > i)
		{
			if (paths[t[i]].size < paths[t[j]].size)
			{
				k = t[i];
				t[i] =  t[j];
				t[j] =  k;
			}
		}
	}
}


void		ft_count(t_graph *graph)
{
	int		i;
	int		j;
	int		total;
	int		nb_f;

	int		t[graph->nbr_next_paths];

	sort(graph->next_paths, t, graph->nbr_next_paths);

	j = 1;
	nb_f = graph->nbr_f;
	graph->count_next_paths = -1;
	i = graph->nbr_next_paths;
	total = 0;
	while (--i >= 0 && (graph->count_next_paths == -1 || graph->count_next_paths > graph->next_paths[t[i]].size))
	{
		total += graph->next_paths[t[i]].size;
		graph->count_next_paths = ((nb_f + total - 1) / j);
		j++;
	}
}

void	ft_distrib_f(t_graph *graph)
{
	int		i;
	int		nb_f;


	int t[graph->nbr_curr_paths];
	sort(graph->curr_paths, t, graph->nbr_curr_paths);



	// for (int k = 0; k < graph->nbr_curr_paths; k++)
	// {
	// 	ft_putnbr((*graph).curr_paths[t[k]].size);
	// 	ft_putchar('\n');
	// }
	// ft_putchar('\n');



	nb_f = (*graph).nbr_f;
	i = (*graph).nbr_curr_paths;
	while (--i >= 0 && nb_f)
	{
		if ((graph->count_curr_paths  - (*graph).curr_paths[t[i]].size + 1) >= nb_f)
			(*graph).curr_paths[t[i]].f = nb_f;
		else
			(*graph).curr_paths[t[i]].f = graph->count_curr_paths  - (*graph).curr_paths[t[i]].size + 1;
		nb_f -= (*graph).curr_paths[t[i]].f;
	}
	while (i >= 0)
	{
		(*graph).curr_paths[t[i]].f = 0;
		i--;
	}
}