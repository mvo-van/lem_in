/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 03:27:31 by hmidoun           #+#    #+#             */
/*   Updated: 2020/02/07 01:07:31 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		init_path(t_graph *graph)
{
	int		i;

	i = -1;
	while (++i < graph->nbr_n)
	{
		graph->tmp_path[i][0] = -1;
		graph->tmp_path[i][1] = graph->nbr_n + 1;
		graph->tmp_path[i][2] = 0;
	}
	graph->stack_path[0] = 0;
	graph->tmp_path[0][0] = 0;
	graph->tmp_path[0][1] = 0;
	graph->tmp_path[0][2] = 1;
	graph->links[0][0] = graph->nbr_n + 1;
}

int			check_1_0_link(t_graph *graph, int i[2])
{
	int j;

	j = -1;
	if (graph->links[graph->tmp_path[graph->stack_path[i[0]]][0]][graph->stack_path[i[0]]] == 1 &&
			graph->links[graph->stack_path[i[0]]][graph->tmp_path[graph->stack_path[i[0]]][0]] == 1)
		return (graph->tmp_path[graph->stack_path[i[0]]][3]);
	return (-1);
}

void		bfs(t_graph *graph)
{
	int		i_link;
	int		ret;
	int		i[2];

	init_path(graph);
	i[0] = 0;
	i[1] = 1;
	while (i[0] < i[1])
	{
		i_link = 0;
		if ((ret = check_1_0_link(graph, i)) < 0)
		{
			while (++i_link < graph->nbr_n)
			{
				if (graph->links[graph->stack_path[i[0]]][i_link] == 1)
				{
					if (graph->tmp_path[i_link][2] == 0)
					{
						graph->stack_path[i[1]] = i_link;
						i[1]++;
						graph->tmp_path[i_link][2] = 1;
					}
					if (graph->tmp_path[i_link][1] > graph->tmp_path[graph->stack_path[i[0]]][1])
					{
						graph->tmp_path[i_link][1] = graph->tmp_path[graph->stack_path[i[0]]][1] + 1;
						graph->tmp_path[i_link][0] = graph->stack_path[i[0]];
					}
				}
			}
		}
		else
		{
			if (graph->tmp_path[ret][2] == 0)
			{
				graph->stack_path[i[1]] = ret;
				i[1]++;
				graph->tmp_path[ret][2] = 1;
			}
			if (graph->tmp_path[ret][1] >= graph->tmp_path[graph->stack_path[i[0]]][1])
			{
				graph->tmp_path[ret][1] = graph->tmp_path[graph->stack_path[i[0]]][1] - 1;
				graph->tmp_path[ret][0] = graph->stack_path[i[0]];
			}
		}
		i[0]++;
	}
}
