/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ret.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 03:44:50 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/27 03:47:26 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_ret(t_list *ret)
{
	t_list	*next;

	if (!ret)
		return ;
	while (ret)
	{
		next = ret->next;
		free(ret);
		ret = next;
	}
}
