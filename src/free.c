/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 03:56:09 by hmidoun           #+#    #+#             */
/*   Updated: 2020/02/08 17:19:04 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_paths(t_graph *graph, int flag)
{
	int	i;

	i = -1;
	if ((flag == 1 || flag == 2) && graph->next_paths)
	{
		while (++i < graph->nbr_next_paths)
		{
			if (&graph->next_paths[i])
			{
				if (graph->next_paths[i].path[0])
				{
					free(graph->next_paths[i].path[0]);
					graph->next_paths[i].path[0] = NULL;
				}
				if (graph->next_paths[i].path)
					free(graph->next_paths[i].path);
			}
		}
		if (graph->next_paths)
		{
			free(graph->next_paths);
			graph->next_paths = NULL;
		}
	}
	i = -1;
	if ((flag == 0 || flag == 2) && graph->curr_paths)
	{
		while (++i < graph->nbr_curr_paths)
		{
			if (&graph->curr_paths[i])
			{
				if (graph->curr_paths[i].path[0])
				{
					free(graph->curr_paths[i].path[0]);
					graph->curr_paths[i].path[0] = NULL;
				}
				if (graph->curr_paths[i].path[1])
				{
					free(graph->curr_paths[i].path[1]);
					graph->curr_paths[i].path[1] = NULL;
				}
				if (graph->curr_paths[i].path)
					free(graph->curr_paths[i].path);
			}
		}
		if (graph->curr_paths)
		{
			free(graph->curr_paths);
			graph->curr_paths = NULL;
		}
	}
}

int		free_graph(t_graph *graph)
{
	int	i;

	i = -1;
	if (graph->links)
	{
		while (++i < graph->nbr_n)
			if (graph->links[i])
				free(graph->links[i]);
		free(graph->links);
	}
	if (graph->stack_path)
		free(graph->stack_path);
	i = -1;
	if (graph->tmp_path)
	{
		while (++i < graph->nbr_n)
			if (graph->tmp_path[i])
				free(graph->tmp_path[i]);
		free(graph->tmp_path);
	}
	free_paths(graph, 2);
	return (0);
}
