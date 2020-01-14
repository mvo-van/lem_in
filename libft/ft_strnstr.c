/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:52:06 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/20 16:00:46 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haystack2;
	char	*needle2;

	haystack2 = (char *)haystack;
	needle2 = (char *)needle;
	i = 0;
	while (haystack2[i])
	{
		j = 0;
		while (haystack2[i] == needle2[j] && haystack2[i] &&
			needle2[j] && i < len)
		{
			i++;
			j++;
		}
		if (!needle2[j])
			return (&haystack2[i - j]);
		i = i - j + 1;
	}
	return (NULL);
}
