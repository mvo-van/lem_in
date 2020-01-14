/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:54:02 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/28 16:41:29 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s1s2 = (char *)malloc(sizeof(*s1s2) * (len + 1))))
		return (NULL);
	while (i < len && s1[i])
	{
		s1s2[i] = s1[i];
		i++;
	}
	while ((i + j) < len && s2[j])
	{
		s1s2[i + j] = s2[j];
		j++;
	}
	s1s2[i + j] = '\0';
	return (s1s2);
}
