/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:01:08 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/28 16:43:14 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*sav;
	t_list	*next;

	if (alst && *alst)
	{
		sav = (*alst);
		while (sav)
		{
			next = sav->next;
			(*del)(sav, sav->content_size);
			sav = next;
		}
		(*alst) = NULL;
	}
}
