NAME = cub3D

SRC =	main.c \
		./src/parsing/check_walls.c \
		./src/parsing/check_case.c \
		./src/parsing/extract_map.c \
		./src/parsing/parsing.c \
		./src/parsing/rgb.c \
		./src/parsing/take_data.c \
		./src/parsing/textures.c \
		./src/utils/free.c \
		./src/utils/ft_len.c \
		./src/utils/ft_salloc.c \
		./src/utils/ft_strcpy_woz.c \
		./src/utils/init.c \
		./src/utils/print_error_free.c \
		./src/utils/print_error.c \
		./src/utils/print.c \
		./src/utils/read.c \
		./src/cub/le_cub.c \
		./src/parsing/take_player.c \
		./src/cub/player_mouve.c \
		./src/cub/print_img.c \
		./src/cub/raycasting.c \
		./src/cub/pixel_to_img.c 

LIBDIR = libft
LIBLIB = libft/libft.a
MLXDIR = MLX42/build
MLXLIB = MLX42/build/libmlx42.a

OBJ = $(SRC:%.c=%.o)

CC = gcc -g -Wall -Wextra -Werror

CFLAGS =  -I.
# 
MLXFLAGS = -lglfw -pthread -lm -ldl -Lmlx

all: $(NAME)

$(LIBLIB):
	make -sC $(LIBDIR)

$(MLXLIB):
	cmake MLX42 -B $(MLXDIR) && make -C $(MLXDIR) -j4

$(NAME): $(OBJ) $(LIBLIB) $(MLXLIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBLIB) $(MLXLIB) $(MLXFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -sC $(LIBDIR) clean
	make -sC $(MLXDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -sC $(LIBDIR) fclean
	rm -rf $(MLXLIB)

re: fclean $(NAME)

.PHONY: all clean fclean re install

install :
	git clone https://github.com/codam-coding-college/MLX42.git
