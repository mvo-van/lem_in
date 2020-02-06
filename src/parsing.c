/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/02/06 16:16:22 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// int		ft_hashtag(char *line)
// {
// 	if (!(ft_strcmp(line, "##start")))
// 		return (FLAG_START);
// 	else if (!(ft_strcmp(line, "##end")))
// 		return (FLAG_END);
// 	return (0);
// }

int		ft_atoi_positif(const char *str)
{
	int		i;
	int		result;
	long	number;

	number = 0;
	result = -1;
	i = 0;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		number = number * 10 + *(str + i) - '0';
		if (number > 2147483647)
			return (-1);
		i++;
	}
	if (*(str + i))
		return (-1);
	result = (int)number;
	return (result);
}

// int		ft_pars_four(char *line, int *nb_four)
// {
// 	int		i;
// 	int		j;

// 	if (line[0] == '#')
// 	{
// 		i = ft_hashtag(line);
// 		if (i & FLAG_START || i & FLAG_END)
// 			return (FLAG_ERREUR);
// 		return (0);
// 	}
// 	else if (!(*line))
// 		return (FLAG_ERREUR);
// 	else
// 	{
// 		j = -1;
// 		while (line[++j])
// 			if (!ft_isdigit(line[j]))
// 				return (FLAG_ERREUR);
// 		*nb_four = ft_atoi(line);
// 		if (*nb_four <= 0)
// 			return (FLAG_ERREUR);
// 		return (DEF_SALLE);
// 	}
// }

int		ft_hashtag(char *line)
{
	// if (line[0] == '\0')
	// 	return (FLAG_ERREUR);
	if (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start"))
			return (FLAG_START);
		if (!ft_strcmp(line, "##end"))
			return (FLAG_END);
		else
			return(FLAG_CMT);
	}
	return (0);
}



int			ft_pars_four(t_graph *graph)
{
	char	*line;
	int		ret;

	while (get_next_line(0, &line) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		ret = ft_hashtag(line);
		if (ret == FLAG_START || ret == FLAG_END)
		{
			free(line);
			return (FLAG_ERREUR);
		}
		if (ret != FLAG_CMT)
		{
			if ((graph->nbr_f = ft_atoi_positif(line)) <= 0)
			{
				free(line);
				return (FLAG_ERREUR);
			}
			free(line);
			return (1);
		}
		free(line);
	}
	return (FLAG_ERREUR);
}

int		check_link(char *line)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	if (line[0] == '#')
		return (0);
	while (line[j])
	{
		if (line[j] == '-')
		{
			count++;
			if (count > 1)
				return (0);
		}
		j++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		ft_isalldigit(char *str)
{
	int		i;

	i = 0;
	while (str + i && *(str + i) >= '0' && *(str + i) <= '9')
		i++;
	if (*(str + i))
		return (0);
	return (1);
}

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

int		get_salle(char *line, t_node *salle)
{
	char	**tab;
	int		i;
	int		x;
	int		y;
	
	i = -1;
	if (line[0] == ' ')
		return (FLAG_ERREUR);
	tab = ft_strsplit(line, ' ');
	while (tab[++i])
	{
		if (i == 0)
		{
			if(ft_verif_salle_name(tab[0],salle) == -1)
				salle->name = ft_strdup(tab[0]);
			else
				break;
		}
		else if (i == 1)
		{
			x = ft_atoi(tab[1]);
			if (!ft_isalldigit(tab[1]))
				break ;
		}
		else if (i == 2)
		{
			y = ft_atoi(tab[2]);
			if (!ft_isalldigit(tab[2]))
				break ;
		}
	}
	ft_free_tab(tab);
	if (i == 3)
		if(ft_verif_salle_coor(x, y, salle) == -1)
		{
			salle->coor.x = x;
			salle->coor.y = y;
			return (1);
		}
	return (FLAG_ERREUR);
}

int		ft_verif_salle_name(char *str, t_node *salle)
{
	salle = ft_next_salle(salle);
	while (salle)
	{
		if (salle->name && !(ft_strcmp(salle->name, str)))
			return (salle->n_node);
		salle = salle->prev;
	}
	return (-1);
}

int		ft_verif_salle_coor(int x, int y, t_node *salle)
{
	salle = ft_next_salle(salle);
	while (salle)
	{
		if (salle->coor.x == x && salle->coor.y == y)
				return (salle->n_node);
		salle = salle->prev;
	}
	return (-1);
}

int		get_link(char *line, t_node *salle, t_graph *graph)
{
	char	**tab;
	int		i;
	int		link_1;
	int		link_2;

	i = -1;
	if (line[0] == ' ')
		return (FLAG_ERREUR);
	tab = ft_strsplit(line, '-');
	while (tab[++i])
	{
		if (i == 0)
			link_1 = ft_verif_salle_name(tab[0], salle);
		else if (i == 1)
			link_2 = ft_verif_salle_name(tab[1], salle);
	}
	ft_free_tab(tab);
	if (link_1 == -1 || link_2 == -1)
		return (FLAG_ERREUR);
	else
	{
		graph->links[link_1][link_2] = 1;
		graph->links[link_2][link_1] = 1;
	}
	if (i == 2)
		return (1);
	return (FLAG_ERREUR);
}

int		ft_free(int **tab, t_node **salle, char *line, int flag)
{
	int i;
	t_node *save;

	*salle = ft_next_salle(*salle);
	i = ((*salle) ? ((*salle)->n_node) : -1);
	if (tab)
	{
		while (i >= 0)
		{
			free(tab[i]);
			i--;
		}
		free(tab);
	}
	while (*salle)
	{
		save = (*salle)->prev;
		if ((*salle)->name)
			free((*salle)->name);
		free(*salle);
		*salle = save;
	}
	*salle = NULL;
	if (line)
		free(line);
	if (flag)
	{
		write(1, "ERREUR\n", 7);
	}
	return (FLAG_ERREUR);
}

#include <stdio.h>

int		ft_creat_tab_link(t_graph *graph, t_node *salle)
{
	int		i;
	int		j;

	salle = ft_next_salle(salle);
	if (!salle)
		return (FLAG_ERREUR);
	i = salle->n_node;
	if (!(graph->links = (int**)malloc(sizeof(int*) * (i + 1))))
		return (FLAG_ERREUR);
	j = 0;
	while (j <= i)
	{
		if (!(graph->links[j] = (int*)malloc(sizeof(int) * (i + 1))))
		{
			while (j-- > 0)
				free(graph->links[j]);
			free(graph->links);
			graph->links = NULL;
			return (FLAG_ERREUR);
		}
		j++;
	}
	//graph->links[j] = NULL;
	ft_tab_zero(graph->links, i + 1, salle->n_node + 1);
	return (i);
}
int		ft_pars_suite(t_graph *graph, t_node **salle)
{
	int		ret;
	char	*line;
	int		res;
	int		flag;
	int		tun;

	res = 0;
	flag = 0;
	tun = 0;
	while (get_next_line(0, &line) > 0)
	{	
		ft_putstr(line);
		ft_putstr("\n");
		ret = ft_hashtag(line);
		res = ((res == 1) ? 1 : check_link(line));
		if (ret != FLAG_CMT && !(res))
		{
			if (ret == FLAG_START || ret == FLAG_END)
			{
				if (flag & ret){
					return (ft_free(graph->links, salle, line, 1));}
				flag |= ret;//ft_putnbr(flag);
				free(line);
				if (get_next_line(0, &line) > 0)
				{
					ft_putstr(line);
					ft_putstr("\n");
				}
				else
				{
					return (ft_free(graph->links, salle, line, 1));
				}
			}
			(*salle) = ft_creat_salle((*salle), ret);
			if (get_salle(line, (*salle)) == FLAG_ERREUR)
				return (ft_free(graph->links, salle, line, 1));
		}
		else if (ret != FLAG_CMT && res)
		{
			if (!((flag & FLAG_START) && (flag & FLAG_END)) || !(check_link(line)))
				return (ft_free(graph->links, salle, line, 1));
			else if (tun == 0)
				ft_creat_tab_link(graph, (*salle));
			tun = 1;
			if (ret == 0 && (get_link(line, (*salle), graph) == FLAG_ERREUR))
				return (ft_free(graph->links, salle, line, 1));
		}
		free(line);
	}
	if (!(graph->links))
		return (ft_free(NULL, salle, NULL, 1));
	return (1);
}

int		ft_parsing(t_node **salle, int ***tab, t_graph *graph)
{
	int		flag;

	*salle = NULL;
	*tab = NULL;
	flag = 0;

	//fd = open("test", O_RDONLY);
	// while (!(flag & FLAG_ERREUR) && (cmp = get_next_line(fd, &line)))
	// {
	// 	ft_putstr(line);
	// 	ft_putchar('\n');
	// 	if (flag == 0)
	if (ft_pars_four(graph) != FLAG_ERREUR)
	{
		if (ft_pars_suite(graph, salle) == FLAG_ERREUR){
			return (FLAG_ERREUR);}
	}
	else
		return (FLAG_ERREUR);
		// if (flag & DEF_SALLE && !(flag & DEF_TUN))
		// 	flag |= ft_pars_salle(line, salle, 0, tab);
		// if (flag & DEF_SALLE && flag & DEF_TUN)
		// {
		// 	flag |= ft_pars_tun(line, salle, tab);
		// 	if (!(flag & FLAG_END) || !(flag & FLAG_START))
		// 		flag |= FLAG_ERREUR;
		// }
		//free(line);
	//}
	// if ((flag & FLAG_ERREUR) || !(*salle) || !(*tab))
	// 	return (ft_free(*tab, salle, 1));
	
	return (0);
}
