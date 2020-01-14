/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 04:08:13 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/27 05:38:30 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_sort_int(int *tab, size_t len)
{
	size_t	i;
	size_t	j;
	int		tam;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tam = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tam;
			}
			j++;
		}
		i++;
	}
}
