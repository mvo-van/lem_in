/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:46:06 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/20 19:00:03 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	j = 0;
	if (size == 0)
	{
		dst[len_dst] = '\0';
		return (len_src);
	}
	else if (len_dst > size)
		return (len_src + size);
	else
	{
		while (src[j] && j + len_dst < size - 1)
		{
			dst[len_dst + j] = src[j];
			j++;
		}
	}
	dst[len_dst + j] = '\0';
	return (len_dst + len_src);
}
