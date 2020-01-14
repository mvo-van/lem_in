/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:34:08 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/27 04:00:00 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_itoa(int n)
{
	long	len;
	int		nb;
	char	*str;
	int		i;

	i = 0;
	len = ft_intlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	nb = n;
	while (len > 1)
	{
		len--;
		str[len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	str[0] = (nb < 0) ? '-' : n % 10 + '0';
	return (str);
}
