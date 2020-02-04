/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:26:15 by midounhoc         #+#    #+#             */
/*   Updated: 2020/02/04 11:13:19 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_id(char *str, char c)
{
	int		id;

	id = 0;
	if (!str)
		return (0);
	while (str[id] && str[id] != c)
		id++;
	return (id);
}

static int			ft_linecpy(char **line, char **temp_buff, int index)
{
	char	*sav;

	if (!(*line = ft_strsub(*temp_buff, 0, index)))
		return (-1);
	if ((*temp_buff)[index] == '\n')
		index++;
	sav = NULL;
	if ((*temp_buff)[index] && !(sav = ft_strdup(&(*temp_buff)[index])))
	{
		free(*line);
		return (-1);
	}
	free(*temp_buff);
	*temp_buff = sav;
	return (1);
}

static t_lst_fd		*ft_new_ptr_lst(int fd)
{
	t_lst_fd	*i;

	if (!(i = (t_lst_fd*)malloc(sizeof(*i))))
		return (NULL);
	i->fd = fd;
	i->buff = NULL;
	i->next = NULL;
	return (i);
}

static int			ft_gnl(t_lst_fd *temp, char **line)
{
	int				index;
	int				size;
	char			buff[BUFF_SIZE + 1];
	char			*sav;

	while ((index = ft_count_id(temp->buff, '\n')) ==
			ft_count_id(temp->buff, '\0'))
	{
		if (BUFF_SIZE <= 0 || (size = read(temp->fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		buff[size] = '\0';
		if (size == 0)
			break ;
		sav = temp->buff;
		temp->buff = ft_strjoin(sav == NULL ? "" : sav, buff);
		free(sav);
	}
	if (!temp->buff && !size)
		return (0);
	return (ft_linecpy(line, &temp->buff, index));
}

int					get_next_line(const int fd, char **line)
{
	static t_lst_fd		*ptr_lst = NULL;
	t_lst_fd			*temp;
	int					ret;

	if (ptr_lst == NULL)
		ptr_lst = ft_new_ptr_lst(fd);
	temp = ptr_lst;
	while (temp->fd != fd && temp->next)
		temp = temp->next;
	if (temp->fd != fd)
	{
		temp->next = ft_new_ptr_lst(fd);
		temp = temp->next;
	}
	ret = ft_gnl(temp, line);
	return (ret);
}
