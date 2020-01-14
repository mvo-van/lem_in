/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/14 18:53:46 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int main ()
{ 
	t_struct    *salle;
	int         **tab;
	int         nb_four;
	//int			i;

	tab = NULL;
	salle = NULL;
	if (ft_parsing(&salle, &tab, &nb_four))
	{
		return (1);
		printf("erreur\n");
	}
	printf("bon!!!\n");
	/*i = salle->num;
	while (salle)
	{
		printf("fourmi %d %s %d %d start %d end %d\n",salle->num, salle->nom, salle->coor.x, salle->coor.y, salle->start, salle->end);
		salle = salle->prev;
	}
	if(tab)
	{
		int j = 0;
		while(j <= i)
		{	
			int k = 0; 
			while(k <= i)
			{
				printf("%d	", tab[j][k]);
				k++;
			}
			j++;
			printf("\n");
		}
	}*/
	ft_free(&tab, &salle);
	return (0);
}
		