/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 07:28:44 by hmidoun           #+#    #+#             */
/*   Updated: 2020/02/07 00:56:36 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		cp_paths(t_graph *graph)
{
	int	i;
	int	j;

	i = -1;
	free_paths(graph, 0);
	graph->nbr_curr_paths = graph->nbr_next_paths;
	graph->count_curr_paths = graph->count_next_paths;
	if (!(graph->curr_paths = malloc(sizeof(t_all_paths) * graph->nbr_curr_paths)))
		return (0);
	while (++i < graph->nbr_curr_paths)
	{
		if (!(graph->curr_paths[i].path = malloc(sizeof(int *) * 2)))
			return (0);
		if (!(graph->curr_paths[i].path[0] = malloc(sizeof(int) * graph->next_paths[i].size)))
			return (0);
		if (!(graph->curr_paths[i].path[1] = malloc(sizeof(int) * graph->next_paths[i].size)))
			return (0);
		j = -1;
		while (++j < graph->next_paths[i].size)
		{
			graph->curr_paths[i].path[0][j] = graph->next_paths[i].path[0][j];
			graph->curr_paths[i].path[1][j] = 0;
		}
		graph->curr_paths[i].size = graph->next_paths[i].size;
	}
	free_paths(graph, 1);
	return (1);
}

int		cmp_paths(t_graph *graph)
{
	bfs(graph);
	if (block_links(graph))
	{
		if (!get_paths(graph))
			return (0);
		ft_count(graph);
		if (!graph->curr_paths)
		{
			if (!cp_paths(graph))
				return (0);
		}
		else if (graph->count_curr_paths >= graph->count_next_paths)
		{
			if (!cp_paths(graph))
				return (0);
		}
		else
			return (-1);
	}
	else
		return (-1);
	return (1);
}

int		optimal_paths(t_graph *graph)
{
	int	ret;

	while ((ret = cmp_paths(graph)) > 0)
		;
	if (ret == 0)
		return (0);
	else if (ret == -1 && graph->count_next_paths == 0)
		return (0);
	else if (ret == -1)
		ft_distrib_f(graph);
	return (1);
}
