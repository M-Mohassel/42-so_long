/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:31:54 by misi-moh          #+#    #+#             */
/*   Updated: 2023/06/28 10:11:43 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/errno.h>
# include <stdio.h>
# include <string.h>

# define TILE 32

typedef struct s_map			t_map;
typedef struct s_position		t_pos;
typedef struct s_data			t_data;
typedef struct s_texture		t_texture;
typedef struct s_idle_texture	t_idle;

enum e_bool
{
	FALSE,
	TRUE
};

struct	s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit[3];
	mlx_texture_t	*player;
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*player_img;
	mlx_image_t		*exit_img[3];

};

struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	char			*collectible_count;
	mlx_texture_t	*player;
	mlx_image_t		*score;
	t_texture		*tiles;
	t_list			*collectible_list;
	mlx_texture_t	*game_icon;
	mlx_image_t		*player_img;
	mlx_image_t		*player_box;
	t_pos			*game_movement[5];
	char			*map_string;
	char			**map;
	int				width;
	int				height;
};

struct s_map
{
	char				**map;
	struct s_position	*player;
	struct s_position	*exit;
	struct s_visited	*visited_list;
	struct s_visited	*double_visited;
	struct s_position	*movements[5];
	char				player_moved;
	int					map_loop;
};

struct s_position
{
	int	x;
	int	y;
};

int		get_collectible_count(char *map);
void	free_and_delete_image(t_data **data, mlx_image_t *image, t_list *head);
void	delete_collectible(t_data **data);
void	player_is_on_colectible(t_data **data);
void	check_if_collected_all(t_data *data);

int		get_count(char *map, char c);
int		is_invalid_component(char c);
int		is_missing_components(char *map);
int		not_valid_map_structure(char **map, size_t array_length);

int		same_coords(t_pos *player, t_pos *exit);
int		not_visited(t_pos *position, t_list *head);
int		is_valid_coord(t_pos position, t_map **map);
t_pos	calculate_coords(t_pos *player, t_pos *movement);

void	add_player_box(t_data **data);
void	draw_enemies(t_data **data);
void	draw_collectables(t_data **data);
void	draw_tiles(t_data **data);
void	draw_map(t_data **data);

int		print_usage(void);
int		components_error(char *map_string);
int		structure_error(t_map *map);
int		no_valid_path(t_map *map);
int		empty_map(char *map_string);

void	init_game_data(t_data **data, char *argv);
void	function_move(t_data *data, t_pos *position);
void	hook(void *param);
void	keyhook(mlx_key_data_t keydata, void *param);
void	game_loop(char *argv);

void	destroy_and_free(t_data **data);
void	ft_lstclear_no_free(t_list **lst);
size_t	ft_arrlength(char **string);

int		is_component(char *str);
int		contains_component(char **map);
int		has_no_valid_path(t_map *map);
int		empty(char *map_string);
int		map_has_errors(char *argv);

int		free_and_return(void *memory);
int		get_bytes(char *map);
char	*read_map(char *map);

int		error_handling(char errnum);
void	free_split(char **split);
int		not_valid_map_name(char *filename);

void	mark_map(t_map **map);
void	copy_coords(t_pos **destination, t_pos **source);
void	move_player_to_new_pos(t_pos *new_pos, t_map **map);
void	step_back(t_map **map);
void	check_map_path(t_map *map);

int		player_is_on_exit(t_data **data);
int		is_valid_move(t_data *data, t_pos *position);
void	init_movements(t_data **data);

void	put_collectable(t_data **data, int width, int height);
void	put_enemy(t_data **data, int width, int height);
void	put_floor(t_data **data, char c, int width, int height);
void	add_player(t_data **data);
void	put_door(t_data **data);

t_pos	*get_player_pos(char **map);
t_pos	*get_exit_pos(char **map);
t_map	*init_structure(char *map_string);
t_pos	*get_component(char **map, char type);
void	destroy_structure(t_map *map);

void	delete_tile_textures(t_data **data);
void	destroy_movements(t_data **data);
void	destroy_tile_structure(t_data **data);

void	load_tile_images(t_data **data);
void	init_tile_textures(t_data **data);

int		not_wall(char c);
int		upper_wall_not_closed(char *upper_wall);
int		lower_wall_not_closed(char *lower_wall);
int		sidewalls_not_closed(char **map, size_t array_length);
int		not_valid_map(char **map);

#endif