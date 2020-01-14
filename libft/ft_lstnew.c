/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:46:11 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/28 16:31:03 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*i;

	if (!(i = (t_list*)malloc(sizeof(*i))))
		return (NULL);
	if (!content)
	{
		i->content = NULL;
		i->content_size = 0;
	}
	else
	{
		i->content = ft_memalloc(content_size);
		i->content_size = content_size;
		i->content = ft_memcpy(i->content, content, content_size);
	}
	i->next = NULL;
	return (i);
}
