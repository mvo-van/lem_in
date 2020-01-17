NAME = visu

SDL2 = ./SDL2.framework

SRC =	main.c \

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

HEADER = ./includes/visu.h \
		 		./../libft/includes/libft.h

INCLUDE_PATH = -I ./includes -I ./../libft/includes

LIBFT =	../libft/libft.a


CC = gcc

FLAGS = -g -lm -framework SDL2 #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADER) $(SDL2)
	$(CC) -o $(NAME)  $(INCLUDE_PATH) $(OBJ) $(LIBFT) $(FLAGS)

# $(SDL2):
# 	-o SDL2-2.0.10.dmg ; hdiutil attach SDL2-2.0.10.dmg ; \
# 	cp -r /Volumes/SDL2/SDL2.framework . ; \
# 	hdiutil detach /Volumes/SDL2 ;

obj:
	mkdir -p obj

obj/%.o: src/%.c $(LIBFT) $(HEADER)| obj
	 $(CC) $(FLAGS)  -c $< -o $@ #$(SDL2)


$(LIBFT):
	make -C ../libft/

clean:
	rm -rf obj
	make clean -C ../libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ../libft/

re: fclean all

.PHONY : all, re, clean, flcean
