# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 16:27:26 by mvo-van-          #+#    #+#              #
#    Updated: 2020/01/14 15:09:57 by mvo-van-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 		=	lem_in
LIB				=	./libft/
SRC				=	srcs/lem_in.c \
					srcs/parsing.c \
					srcs/pars_salle.c \
					srcs/pars_tubes.c \
					srcs/list.c \

OBJ    			=	$(SRC:.c=.o)
CFLAGS		   	=	-Wall -Werror -Wextra -I includes

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	gcc -o  $(NAME) $(OBJ) $(CFLAGS) libft/libft.a

clean:
		make -C $(LIB) clean
	    rm -f $(OBJ)
fclean: clean
		make -C $(LIB) fclean
	    rm -f $(NAME)
re: fclean all

.PHONY : all, $(NAME), clean, fclean, re