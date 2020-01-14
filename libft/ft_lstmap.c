/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:34:54 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/28 16:32:35 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new;
	t_list	*sav;

	ret = NULL;
	if (lst)
	{
		while (lst)
		{
			if (!(new = (t_list*)malloc(sizeof(t_list))))
			{
				ft_free_ret(ret);
				return (NULL);
			}
			new = (*f)(lst);
			if (ret == NULL)
				ret = new;
			else
				sav->next = new;
			sav = new;
			lst = lst->next;
		}
	}
	return (ret);
}
