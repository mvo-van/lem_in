/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:27:11 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/27 05:55:32 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (i > j)
	{
		if (!(s2 = (char *)malloc(sizeof(*s2) * 1)))
			return (NULL);
		*s2 = '\0';
		return (s2);
	}
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	s2 = ft_strsub(s, i, j - i + 1);
	return (s2);
}
