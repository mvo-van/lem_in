/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:24:35 by hmidoun           #+#    #+#             */
/*   Updated: 2020/02/10 18:40:20 by mvo-van-         ###   ########.fr       */
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

int		main(void)
{
	t_graph		graph;
	t_node		*salle;
	int			ret;

	ret = 1;
	salle = NULL;
	if (ft_parsing(&salle, &((graph).links), &graph) == FLAG_ERREUR)
		return (0);
	ft_tab_salle(salle, &graph);
	if (!set_matrix(&graph) || !(ret = optimal_paths(&graph)))
	{
		if (!ret)
			ft_putstr("ERROR\n");
		ft_free(NULL, &salle, NULL, 0);
		free(graph.tab_nodes);
		free_graph(&graph);
		return (0);
	}
	output_algo(graph);
	free_graph(&graph);
	ft_free(NULL, &salle, NULL, 0);
	free(graph.tab_nodes);
	return (0);
}
