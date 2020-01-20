/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:24:35 by hmidoun           #+#    #+#             */
/*   Updated: 2020/01/20 13:28:12 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			set_matrix(t_graph *graph)
{
	int		i;

	if (!(graph->tmp_path = malloc(sizeof(int*) * graph->nbr_n)))
		return (0);
	if (!(graph->stack_path = malloc(sizeof(int) * graph->nbr_n)))
		return (0);
	i = -1;
	while (++i < graph->nbr_n)
	{
		if(!(graph->tmp_path[i] = malloc(sizeof(int) * 3)))
			return (0);
		graph->tmp_path[i][0] = -1;
		graph->tmp_path[i][1] = -1;
		graph->tmp_path[i][2] = 0;
	}
	return (1);
}

int		ft_tab_salle(t_node *salle, t_graph *graph)
{
	int		i;

	i = 0;
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

int 	main()
{
	t_graph		graph;
	t_node		*salle;

	salle = NULL;
	if (ft_parsing(&salle, &((graph).links), &((graph).nbr_f)))
		return (0);
	ft_tab_salle(salle, &graph);
	if (!set_matrix(&graph))
		return (free_graph(&graph));
	
	int i = 0;
	while(i < graph.nbr_n)
	{
		ft_putchar('\t');
		ft_putstr(graph.tab_nodes[i].name);
		ft_putchar('\n');
		i++;
	}
	/*for (int i=0; i < graph.nbr_n ; i++)
	{
			for (int j=0;j<graph.nbr_n ; j++)
			{
				ft_putnbr(graph.links[i][j]);
				ft_putchar('\t');
			}
			ft_putchar('\n');
	}*//*
	graph.links[0][2] = 1;
	graph.links[0][6] = 1;
	graph.links[0][10] = 1;

	graph.links[2][3] = 1;
	graph.links[3][4] = 1;
	graph.links[4][5] = 1;

	graph.links[6][7] = 1;
	graph.links[7][8] = 1;
	graph.links[8][9] = 1;

	graph.links[10][11] = 1;
	graph.links[11][12] = 1;
	graph.links[12][13] = 1;

	graph.links[10][7] = 1;
	graph.links[7][5] = 1;

	graph.links[5][1] = 1;
	graph.links[9][1] = 1;
	graph.links[13][1] = 1;

	for (int i=0;i<graph.nbr_n ; i++)
	{
			for (int j=0;j<graph.nbr_n ; j++)
			{
				if (graph.links[i][j] == 1)
					graph.links[j][i] = 1;
			}
	}*/
	// graph.links[6][7] = 15;
	// graph.links[7][5] = 15;
	// graph.links[5][1] = 15;

	
	bfs(&graph);
	block_links(&graph);
	
	/*bfs(&graph);
	block_links(&graph);
	
	bfs(&graph);
	block_links(&graph);

	bfs(&graph);
	block_links(&graph);*/
	// bfs(&graph);
	// block_links(&graph);
	//bfs(&graph);
	// block_links(&graph);
	// for (int i=0;i<graph.nbr_n ; i++)
	// {
	// 	ft_putnbr(i);
	// 	ft_putchar('\t');
	// 	ft_putnbr(graph.tmp_path[i][0]);
	// 	ft_putchar('\t');
	// 	ft_putnbr(graph.tmp_path[i][1]);
	// 	ft_putchar('\n');
	// }
	// 	ft_putchar('\n');		
	
	if (!get_paths(&graph)){
		return(free_graph(&graph));}
	// if (!graph.curr_paths)
	// 	graph.curr_paths = graph.next_paths;
	// else
	// {
	// 	if(test(next_paths, curr_path))
	// 	{
	// 		free(curr_paths);
	// 		copy next to curr
	// 		free (next);
	// 	}
	// 	else
	// 	{
	// 		finish bfs
	// 	}

	// }
	


	int count = ft_count(graph);
	ft_distrib_f(&graph, count);
	ft_putnbr(count);
	ft_putchar('\n');
	for(int i= 0; i < graph.nbr_next_paths; i++)
	{
		for (int j = 0; j < graph.next_paths[i].size; j++)
		{
			ft_putnbr(graph.next_paths[i].path[j]);
			ft_putchar('\t');
		}
		ft_putchar('\n');
		ft_putnbr(graph.next_paths[i].f);
		ft_putchar('\n');
	}
	
	free_graph(&graph);
	//while (1)
	return (0);
}
