/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:00:06 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/14 16:44:23 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	char	*s22;

	s22 = (char *)s2;
	len = ft_strlen(s1);
	i = 0;
	while (s22[i])
	{
		s1[len + i] = s22[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}
