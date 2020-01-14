/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:14:56 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/13 19:22:30 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*src;
	size_t	i;

	i = 0;
	if (!(src = (char*)malloc(sizeof(*src) * size)))
		return (NULL);
	while (i < size)
	{
		src[i] = 0;
		i++;
	}
	return (src);
}
