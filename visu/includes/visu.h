/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:00:41 by midounhocin       #+#    #+#             */
/*   Updated: 2019/09/15 21:36:22 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef visu_H
# define visu_H

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
# include "../../libft/includes/libft.h"

# define SUCCESS			1
# define FAIL				0
# define X_SCREEN			1251
# define Y_SCREEN			811
# define Y_min				125

typedef struct s_sdl_setup	t_sdl_setup;
struct	s_sdl_setup
{
	SDL_Window		*window;
	SDL_Renderer	*render;
};

#endif
