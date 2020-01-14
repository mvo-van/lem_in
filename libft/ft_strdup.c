/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:32:05 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/20 15:48:32 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*cp;
	size_t	len;
	size_t	i;
	char	*s12;

	s12 = (char *)s1;
	i = 0;
	len = ft_strlen(s12);
	if (!(cp = (char*)malloc(sizeof(*s12) * (len + 1))))
		return (NULL);
	while (s12[i])
	{
		cp[i] = s12[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
