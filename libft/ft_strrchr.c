/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:28:15 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/20 15:51:54 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*s2;

	s2 = (char *)s;
	len = ft_strlen(s2);
	while (s2[len] != s2[0] && s2[len] != c)
		len--;
	if (s2[len] == c)
		return (&s2[len]);
	return (NULL);
}
