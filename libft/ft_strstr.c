/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:39:13 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/20 15:36:21 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*haystack2;
	char	*needle2;

	haystack2 = (char *)haystack;
	needle2 = (char *)needle;
	i = 0;
	if (ft_strlen(needle) == 0)
		return (haystack2);
	while (haystack2[i])
	{
		j = 0;
		while (haystack2[i] == needle2[j] && haystack2[i] && needle2[j])
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
