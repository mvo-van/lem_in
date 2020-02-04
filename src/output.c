/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 07:27:14 by hmidoun           #+#    #+#             */
/*   Updated: 2020/02/04 19:22:23 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	output_str(t_graph graph,int i, int j)
{
	//printf("L%d-%s ",graph.curr_paths[i].path[1][j + 1], graph.tab_nodes[graph.curr_paths[i].path[0][j + 1]].name);
	ft_putchar('L');
	ft_putnbr(graph.curr_paths[i].path[1][j + 1]);
	ft_putchar('-');
	ft_putstr(graph.tab_nodes[graph.curr_paths[i].path[0][j + 1]].name);
	ft_putchar(' ');
}

void	output_algo(t_graph graph)
{
	int i;
	int f;
	int j;
	int flag;

	flag = -1;
	f = 1;
	while (++flag < graph.count_curr_paths)
	{
		i = -1;
		ft_putchar('\n');
		while (++i < graph.nbr_curr_paths)
		{
			j = graph.curr_paths[i].size - 1;
			while (--j >= 0)
			{
				if (graph.curr_paths[i].path[1][j])
				{
					graph.curr_paths[i].path[1][j + 1] = graph.curr_paths[i].path[1][j];
					output_str(graph, i, j);
					graph.curr_paths[i].path[1][j] = 0;
				}
			}
			if (graph.curr_paths[i].f)
			{
				graph.curr_paths[i].path[1][0] = f;
				output_str(graph, i, -1);
				f++;
				graph.curr_paths[i].f--;
			}
		}
	 }
	 ft_putchar('\n');
}
