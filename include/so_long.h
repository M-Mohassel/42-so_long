/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:31:54 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/18 15:36:12 by misi-moh         ###   ########.fr       */
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data
{
	mlx_t		*mlx;
	int			map_height;
	int			map_length;
	char		*map_string;
	int			game_over;
	void		*walls;
	void		*exit;
	void		*player;
	char		**map;
	int			drawP;
	char		*err_msg;
	mlx_image_t	*img;
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