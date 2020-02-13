/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:24:35 by hmidoun           #+#    #+#             */
/*   Updated: 2020/02/13 13:35:00 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		set_matrix(t_graph *graph)
{
	int		i;

	if (!(graph->tmp_path = malloc(sizeof(int*) * graph->nbr_n)))
		return (0);
	if (!(graph->stack_path = malloc(sizeof(int) * graph->nbr_n)))
		return (0);
	i = -1;
	while (++i < graph->nbr_n)
	{
		if (!(graph->tmp_path[i] = malloc(sizeof(int) * 4)))
			return (0);
		graph->tmp_path[i][3] = -1;
	}
	return (1);
}

int		ft_tab_salle(t_node *salle, t_graph *graph)
{
	int		i;

	i = 0;
	salle = ft_next_salle(salle);
	if (salle)
		graph->nbr_n = salle->n_node + 1;
	else
		graph->nbr_n = 0;
	salle = ft_prev_salle(salle);
	if (!(graph->tab_nodes =
		(t_node *)malloc(sizeof(t_node) * (graph->nbr_n))))
		return (0);
	while (salle && i < graph->nbr_n)
	{
		graph->tab_nodes[i] = *salle;
		i++;
		salle = salle->next;
	}
	return (1);
}

int		free_all(t_graph *graph, t_node *salle)
{
	ft_free(NULL, &salle, NULL, 0);
	free(graph->tab_nodes);
	free_graph(graph);
	return (0);
}

int		main(void)
{
	t_graph		graph;
	t_node		*salle;

	salle = NULL;
	if (ft_parsing(&salle, &((graph).links), &graph) == FLAG_ERREUR)
		return (0);
	if (!ft_tab_salle(salle, &graph))
	{
		ft_free(NULL, &salle, NULL, 0);
		return (0);
	}
	if (!set_matrix(&graph))
	{
		ft_free(NULL, &salle, NULL, 0);
		free(graph.tab_nodes);
	}
	if (!optimal_paths(&graph))
	{
		ft_putstr("ERROR\n");
		return (free_all(&graph, salle));
	}
	output_algo(graph);
	return (free_all(&graph, salle));
}
