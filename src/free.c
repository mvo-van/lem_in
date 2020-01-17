/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 03:56:09 by hmidoun           #+#    #+#             */
/*   Updated: 2020/01/12 08:29:37 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_paths(t_graph *graph, int flag)
{
	int	i;

	i = -1;
	if (flag == 1 || flag == 2)
	{
		while (++i < graph->nbr_next_paths)
		{
			if (&graph->next_paths[i])
			{
				if (graph->next_paths[i].path)
					free(graph->next_paths[i].path);
			}
		}
		if (graph->next_paths)
			free(graph->next_paths);
	}
	i = -1;
	if (flag == 0 || flag == 2)
	{
		while (++i < graph->nbr_curr_paths)
		{
			if (&graph->curr_paths[i])
			{
				if (graph->curr_paths[i].path)
					free(graph->curr_paths[i].path);
			}
		}
		if (graph->curr_paths)
			free(graph->curr_paths);
	}
}

int			free_graph(t_graph *graph)
{
	int	i;

	i = -1;
	while (++i < graph->nbr_n)
	{
		if (graph->links[i])
			free(graph->links[i]);
	}
	if (graph->links)
		free(graph->links);
	if (graph->stack_path)
		free(graph->stack_path);
	i = -1;
	while (++i < graph->nbr_n)
	{
		if (graph->tmp_path[i])
			free(graph->tmp_path[i]);
	}
	if (graph->tmp_path)
		free(graph->tmp_path);
	free_paths(graph, 2);

	return (0);
}
