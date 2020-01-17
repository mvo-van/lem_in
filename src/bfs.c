/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 03:27:31 by hmidoun           #+#    #+#             */
/*   Updated: 2020/01/12 05:27:42 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			cond_path_change(t_graph *graph, int k, int i)
{
	if ((graph->links[graph->stack_path[i]][k] == 1) &&
		((graph->tmp_path[k][1] == -1) ||
		graph->tmp_path[k][1] >
		graph->tmp_path[graph->stack_path[i]][1]))
		return (1);
	return (0);
}

void		init_path(t_graph *graph)
{
	int		i;

	i = -1;
	while (++i < graph->nbr_n)
	{
		graph->tmp_path[i][0] = -1;
		graph->tmp_path[i][1] = -1;
		graph->tmp_path[i][2] = 0;
	}
	graph->stack_path[0] = 0;
	graph->tmp_path[0][0] = 0;
	graph->tmp_path[0][1] = 0;
}

void		bfs_conditions(t_graph *graph, int *i_link, int *tmp, int i[2])
{
	if (graph->links[graph->stack_path[i[0]]]
		[graph->tmp_path[graph->stack_path[i[0]]][0]] == graph->nbr_n + 1)
	{
		graph->tmp_path[*i_link][1] =
				graph->tmp_path[graph->stack_path[i[0]]][1] + 1;
	}
	else if (graph->links[*i_link][graph->stack_path[i[0]]] == graph->nbr_n + 1)
	{
		i[1] -= *tmp;
		*tmp = -2;
		graph->tmp_path[*i_link][1] =
				graph->tmp_path[graph->stack_path[i[0]]][1] - 1;
	}
	else
		graph->tmp_path[*i_link][1] =
				graph->tmp_path[graph->stack_path[i[0]]][1] + 1;
	if (!graph->tmp_path[*i_link][2])
	{
		graph->stack_path[i[1]] = *i_link;
		i[1]++;
		graph->tmp_path[*i_link][2] = 1;
	}
	graph->tmp_path[*i_link][0] = graph->stack_path[i[0]];
}

void		bfs(t_graph *graph)
{
	int		i_link;
	int		tmp;
	int		i[2];

	init_path(graph);
	i[0] = 0;
	i[1] = 1;
	while (i[0] < i[1])
	{
		i_link = -1;
		tmp = 0;
		while (++i_link < graph->nbr_n && tmp >= 0)
		{
			if (cond_path_change(graph, i_link, i[0]))
			{
				bfs_conditions(graph, &i_link, &tmp, i);
				tmp++;
			}
		}
		i[0]++;
	}
}
