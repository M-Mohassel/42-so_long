NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -L./lib/libft -lft -ldl -lglfw -pthread -lm
LIBFT	:= ./lib/libft/libft.a
LIBFT_DIR	= ./lib/libft
SRCS	:= \
	./src/collectable.c ./src/component_check.c ./src/coord_utils.c ./src/draw_map.c \
	./src/errors.c ./src/loop.c ./src/main.c ./src/map.c ./src/map_check.c \
	./src/name_check.c ./src/path_check.c ./src/player_utils.c ./src/put_tile.c \
	./src/struct_utils.c ./src/tiles.c ./src/tile_utils.c ./src/wall_check.c

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(LIBMLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(LIBMLX) :
	@if ! [ -d "./lib/MLX42/build" ]; then \
	git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	cd $(LIBMLX) && cmake -B build && cmake --build build -j4;\
	fi

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@rm -fr $(LIBMLX)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
