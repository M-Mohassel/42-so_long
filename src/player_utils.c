/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:11:48 by misi-moh          #+#    #+#             */
/*   Updated: 2023/06/16 11:48:12 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*void	player_is_on_enemy(t_data **data)
{
	mlx_instance_t	*player;
	mlx_image_t		*enemy;
	t_list			*current;
	int				posx;
	int				posy;

	current = (*data)->enemy_list;
	player = (*data)->player_box->instances;
	while (current)
	{
		enemy = current->position;
		if ((enemy->instances[0].x / TILE + 1)
			== (player[0].x / TILE) && (enemy->instances[0].y / TILE + 1)
			== (player[0].y / TILE))
			mlx_close_window((*data)->mlx);
		current = current->next;
	}
	posx = player[0].x / TILE;
	posy = player[0].y / TILE;
	if ((*data)->map[posy][posx] == 'C')
	{
		(*data)->map[posy][posx] = '0';
		delete_collectible(data);
	}
}*/

int	player_is_on_exit(t_data **data)
{
	mlx_instance_t	*player;
	mlx_instance_t	*exit;

	player = &(*data)->player_box->instances[0];
	exit = &(*data)->tiles->exit_img[0]->instances[0];
	if (player->x == exit->x && player->y == exit->y)
		return (1);
	return (0);
}

/*void	idle_animation(void *param)
{
	t_data			*data;
	mlx_image_t		**player;
	static int		frames;
	static int		i;

	data = param;
	player = data->idle->right_idle;
	if (frames == 0 || frames % 7 == 0)
	{
		ft_memcpy(player[0]->pixels, player[i]->pixels,
			SPRITE * SPRITE * 4);
		if (i == 7)
		{
			frames = -1;
			i = -1;
		}
		i++;
	}
	frames++;
}*/

int	is_valid_move(t_data *data, t_pos *position)
{
	mlx_instance_t	*player;
	int				posx;
	int				posy;

	posx = position->x;
	posy = position->y;
	player = data->player_box->instances;
	posx = posx + player->x / TILE;
	posy = posy + player->y / TILE;
	if (data->map[posy][posx] != '1')
		return (1);
	return (0);
}

void	init_movements(t_data **data)
{
	(*data)->game_movement[0] = (t_pos *)malloc(sizeof(t_pos));
	(*data)->game_movement[1] = (t_pos *)malloc(sizeof(t_pos));
	(*data)->game_movement[2] = (t_pos *)malloc(sizeof(t_pos));
	(*data)->game_movement[3] = (t_pos *)malloc(sizeof(t_pos));
	(*data)->game_movement[4] = NULL;
	(*data)->game_movement[0]->x = 0;
	(*data)->game_movement[0]->y = -1;
	(*data)->game_movement[1]->x = 0;
	(*data)->game_movement[1]->y = 1;
	(*data)->game_movement[2]->x = 1;
	(*data)->game_movement[2]->y = 0;
	(*data)->game_movement[3]->x = -1;
	(*data)->game_movement[3]->y = 0;
}
