/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 03:23:33 by hmidoun           #+#    #+#             */
/*   Updated: 2020/01/21 06:03:15 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		block_links(t_graph *graph)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	if (graph->tmp_path[i][0] == -1)
		return (0);
	while (i)
	{
		j = graph->tmp_path[i][0];
		graph->links[j][i] = graph->nbr_n + 1;
		k = graph->links[j][i];
		i = graph->tmp_path[i][0];
	}
	return (1);
}

int			nbr_paths(t_graph *graph)
{
	int	i;

	graph->nbr_next_paths = 0;
	i = -1;
	while (++i < graph->nbr_n)
	{
		if (graph->links[1][i] == 1 && graph->links[i][1] == graph->nbr_n + 1)
			graph->nbr_next_paths++;
	}
	return (graph->nbr_next_paths);
}

void		fill_paths(t_graph *graph, int i[3], int *n)
{
	if (graph->links[i[1]][i[0]] == 1 &&
		graph->links[i[0]][i[1]] == graph->nbr_n + 1)
	{
		if (i[0] == 0)
			i[2] = i[1];
		graph->next_paths[*n].path[0][graph->next_paths[*n].size] = i[1];
		graph->next_paths[*n].size++;
		i[0] = i[1];
		i[1] = 0;
	}
	if (i[0] == 1)
		(*n)--;
}

int			get_paths(t_graph *graph)
{
	int	n;
	int	i[3];

	n = nbr_paths(graph);
	if (!(graph->next_paths = malloc(sizeof(t_all_paths) * n)))
		return (0);
	n--;
	i[2] = 0;
	while (n >= 0 && ++i[2] < graph->nbr_n)
	{
		if (!(graph->next_paths[n].path = malloc(sizeof(int [2]) * graph->nbr_n)))
			return (0);
		if (!(graph->next_paths[n].path[0]= malloc(sizeof(int) * graph->nbr_n)))
			return (0);
		// if (!(graph->next_paths[n].path[1]= malloc(sizeof(int) * graph->nbr_n)))
		// 	return (0);
		i[0] = 0;
		i[1] = i[2] - 1;
		graph->next_paths[n].size = 0;
		while (++i[1] < graph->nbr_n && i[0] != 1)
			fill_paths(graph, i, &n);
	}
	return (1);
}
