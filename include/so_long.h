/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:31:54 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/25 13:15:52 by misi-moh         ###   ########.fr       */
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

# define KEY_ESC 65307
# define SPRITE 64
# define TILE 32

# define TREE "./assets/baum1.xpm"

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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	char			*collectible_count;
	mlx_texture_t	*player;
	mlx_image_t		*score;
	t_idle			*idle;
	t_texture		*tiles;
	t_list			*collectible_list;
	t_list			*enemy_list;
	mlx_texture_t	*game_icon;
	mlx_image_t		*player_img;
	mlx_image_t		*player_box;
	t_pos			*enemy_movement[5];
	char			*map_string;
	char			**map;
	int				width;
	int				height;
};

struct	s_idle_texture
{
	mlx_texture_t	*left[9];	
	mlx_texture_t	*right[9];	
	mlx_image_t		*right_idle[9];	
	mlx_image_t		*left_idle[9];	
	mlx_image_t		*idle;
};

enum e_bool
{
	FALSE,
	TRUE
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

void	draw_map(t_data **data);
int		print_usage(void);
int		components_error(char *map_string);
int		structure_error(t_map *map);
int		no_valid_path(t_map *map);
int		empty_map(char *map_string);
void	init_game_data (t_data **data, char *argv);
void	game_loop (char *argv);
size_t	ft_arrlength(char **string);
int		has_no_valid_path(t_map *map);
int		empty(char *map_string);
int		map_has_errors(char *argv);
char	*read_map(char *map);
int		get_bytes(char *map);
int		free_and_return(void *memory);
int		not_valid_map_name(char *filename);
void	free_split(char **split);
int		error_handling(char errnum);




#endif