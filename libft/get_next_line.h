/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 01:11:52 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/12/07 06:08:17 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

typedef struct		s_lst_fd
{
	int					fd;
	char				*buff;
	struct s_lst_fd		*next;
}					t_lst_fd;

int					get_next_line(const int fd, char **line);

#endif
