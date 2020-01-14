/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:45:41 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/10 13:16:55 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		len;

	if (!s || !(tab = (char**)ft_memalloc(sizeof(char*) * (ft_word(s, c) + 1))))
		return (NULL);
	len = 0;
	j = 0;
	while (s[len])
	{
		i = 0;
		while (s[len] == c)
			len++;
		while (s[len] && s[len] != c)
		{
			i++;
			len++;
		}
		if (i != 0 && !(tab[j] = ft_strsub(s, len - i, i)))
			return (NULL);
		j++;
	}
	return (tab);
}
