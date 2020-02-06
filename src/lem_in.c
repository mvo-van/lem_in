/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:24:35 by hmidoun           #+#    #+#             */
/*   Updated: 2020/02/06 15:28:47 by mvo-van-         ###   ########.fr       */
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
	// if (!(graph->paths_order = malloc(sizeof(int) * graph->nbr_n)))
	// 	return (0);
	i = -1;
	while (++i < graph->nbr_n)
	{
		if(!(graph->tmp_path[i] = malloc(sizeof(int) * 4)))
			return (0);
		graph->tmp_path[i][3] = -1;
		// graph->tmp_path[i][1] = -1;
		// graph->tmp_path[i][2] = 0;
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




int 	main()
{
	t_graph		graph;
	t_node		*salle;

	fd = open("tst",O_RDONLY);
	salle = NULL;
	if (ft_parsing(&salle, &((graph).links), &graph) == FLAG_ERREUR)
	{
		
		//while(1);
		return (0);
	}
	
	ft_tab_salle(salle, &graph);
//ft_putnbr(graph.nbr_f);

	if (!set_matrix(&graph))
	{
		return (free_graph(&graph));
	}
	// for(int i = 0; i < graph.nbr_n; i++)
	// {
	// 	for (int j = 0; j < graph.nbr_n; j++)
	// 	{
	// 		ft_putnbr(graph.links[i][j]);
	// 		ft_putchar('\t');
	// 	}
	// 	ft_putchar('\n');
	// }




	if(!optimal_paths(&graph))
		return (free_graph(&graph));

	output_algo(graph);
	free_graph(&graph);
	ft_free(NULL, &salle, NULL, 0);
	free(graph.tab_nodes);



// 	bfs(&graph);
// 	block_links(&graph);

// 	bfs(&graph);
// 	block_links(&graph);

// 	bfs(&graph);
// 	block_links(&graph);

// 	bfs(&graph);
// 	block_links(&graph);
// 	bfs(&graph);
// 	block_links(&graph);
// bfs(&graph);
// 	block_links(&graph);
// bfs(&graph);
// 	block_links(&graph);
// bfs(&graph);
// 	block_links(&graph);
// bfs(&graph);
// 	block_links(&graph);
// bfs(&graph);
// 	block_links(&graph);
// bfs(&graph);
// 	block_links(&graph);


// 	get_paths(&graph);
// 	cp_paths(&graph);


		// for (int j = 0; j < graph.nbr_n; j++)
		// {
		// 	if (ft_strcmp(graph.tab_nodes[j].name, "Oj_4") == 0)
		// 		ft_putnbr(j);
		// }


	// //while (1);
	// ft_putnbr(graph.count_curr_paths);
	// ft_putstr("................count \n");
	// ft_putnbr(graph.nbr_curr_paths);
	// ft_putstr("............... graph.nbr_curr_paths\n");
	// for(int i = 0; i < graph.nbr_curr_paths; i++)
	// {
	// 	for (int j = 0; j < graph.curr_paths[i].size; j++)
	// 	{
	// 		ft_putstr(graph.tab_nodes[graph.curr_paths[i].path[0][j]].name);
	// 		ft_putchar('\t');
	// 	}
	// 	ft_putchar('\n');
	// 	ft_putnbr(graph.curr_paths[i].f);
	// 	ft_putchar('\n');
	// 	ft_putnbr(graph.curr_paths[i].size);
	// 	ft_putchar('\n');
	// 	ft_putnbr(graph.curr_paths[i].f + graph.curr_paths[i].size);
	// 	ft_putchar('\n');
	// }
	// free_graph(&graph);
	// ft_putchar('\n');











// graph.nbr_f = 5;
// graph.nbr_n = 14;
// graph.links = malloc(sizeof(int *) * graph.nbr_n);



// 	for (int i=0; i < graph.nbr_n ; i++)
// 	{
// 			graph.links[i] = malloc(sizeof(int ) * graph.nbr_n);
// 		for (int j=0; j < graph.nbr_n ; j++)
// 		{
// 			graph.links[i][j] = graph.nbr_n + 1;
// 		}
// 	}

// 	graph.links[0][2] = 1;
// 	graph.links[0][10] = 1;
// 	graph.links[2][3] = 1;
// 	graph.links[3][4] = 1;
// 	graph.links[4][5] = 1;
// 	graph.links[1][5] = 1;
//  	graph.links[0][6] = 1;

//  graph.links[7][6] = 1;
//  	graph.links[7][8] = 1;
// 	 graph.links[8][9] = 1;
// 	graph.links[9][1] = 1;
// 	 graph.links[10][11] = 1;
// 	 graph.links[11][12] = 1;
// 	 	 graph.links[10][7] = 1;
// 	graph.links[7][5] = 1;
// 	 graph.links[12][13] = 1;
// 	 graph.links[13][1] = 1;

// 	for (int i=0;i<graph.nbr_n ; i++)
// 	{
// 			for (int j=0;j<graph.nbr_n ; j++)
// 			{
// 				if (graph.links[i][j] == 1)
// 					graph.links[j][i] = 1;
// 			}
// 	}
// //  graph.links[0][3] = graph.nbr_n + 1;
// //  graph.links[3][4] = graph.nbr_n + 1;
// //  graph.links[2][1] = graph.nbr_n + 1;
//  //graph.links[3][8] = graph.nbr_n + 1;


// optimal_paths(&graph);
// // bfs(&graph);
// // block_links(&graph);
// // bfs(&graph);
// // block_links(&graph);
// // bfs(&graph);
// // block_links(&graph);
// // bfs(&graph);
// // block_links(&graph);
// // bfs(&graph);
// // block_links(&graph);
// // bfs(&graph);
// // block_links(&graph);
// // get_paths(&graph);
// 	for(int i = 0; i < graph.nbr_curr_paths; i++)
// 	{
// 		for (int j = 0; j < graph.curr_paths[i].size; j++)
// 		{
// 			ft_putnbr(graph.curr_paths[i].path[0][j]);
// 			ft_putchar('\t');
// 		}
// 		ft_putchar('\n');
// 		ft_putnbr(graph.curr_paths[i].f);
// 		ft_putchar('\n');
// 	}











	// bfs(&graph);
	// block_links(&graph);

	// bfs(&graph);
	// block_links(&graph);

	// bfs(&graph);
	// block_links(&graph);

	// bfs(&graph);
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

	// if (!get_paths(&graph)){
	// 	return(free_graph(&graph));}
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


	while (1);
	return (0);
}
