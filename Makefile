NAME = lem_in

SRC =	lem_in.c \
		get_path.c \
		bfs.c \
		free.c \
		count.c \
		list.c \
		pars_salle.c \
		pars_tubes.c \
		parsing.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

HEADER = ./includes/lem_in.h \
		 ./libft/includes/libft.h

INCLUDE_PATH = -I ./includes -I ./libft/includes

LIBFT =	libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(INCLUDE_PATH) $(OBJ) -o $(NAME) $(LIBFT)

obj:
	mkdir -p obj

obj/%.o: src/%.c $(LIBFT) | obj
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE_PATH)


$(LIBFT):
	make -C ./libft/

clean:
	rm -rf obj
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean
