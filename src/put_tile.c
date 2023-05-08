/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:13:41 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/29 14:00:56 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_collectable(t_data **data, int width, int height)
{
	mlx_texture_t	*tiles;
	mlx_image_t		*image;

	tiles = mlx_load_png("assets/tiles/other/35.png");
	image = mlx_texture_to_image((*data)->mlx, tiles);
	if ((*data)->map[height][width] == 'C')
	{
		ft_lstadd_front(&((*data)->collectible_list), ft_lstnew(image));
		((*data)->collectible_list)->x = width;
		((*data)->collectible_list)->y = height;
		mlx_image_to_window((*data)->mlx,
			((*data)->collectible_list)->position, width * TILE, height * TILE);
	}
	mlx_delete_texture(tiles);
}

void	put_enemy(t_data **data, int width, int height)
{
	mlx_texture_t	*tiles;
	mlx_image_t		*image;

	tiles = mlx_load_png("assets/enemy/idle/1.png");
	image = mlx_texture_to_image((*data)->mlx, tiles);
	if ((*data)->map[height][width] == 'G')
	{
		ft_lstadd_front(&((*data)->enemy_list), ft_lstnew(image));
		((*data)->enemy_list)->x = width;
		((*data)->enemy_list)->y = height;
		mlx_image_to_window((*data)->mlx, ((*data)->enemy_list)->position,
			width * TILE - 14, height * TILE - 16);
	}
	mlx_delete_texture(tiles);
}

void	put_floor(t_data **data, char c, int width, int height)
{
	t_texture	*tiles;

	tiles = (*data)->tiles;
	if (c == '1')
		mlx_image_to_window((*data)->mlx, tiles->wall_img, width, height);
	else
		mlx_image_to_window((*data)->mlx, tiles->floor_img, width, height);
}

void	add_player(t_data **data)
{
	int			posx;
	int			posy;
	t_idle		*player;
	t_pos		*player_pos;

	player_pos = get_component((*data)->map, 'P');
	posx = player_pos->x * TILE;
	posy = player_pos->y * TILE;
	player = (*data)->idle;
	mlx_image_to_window((*data)->mlx, player->right_idle[0],
		posx - 16, posy - 24);
	free(player_pos);
}

void	put_door(t_data **data)
{
	t_texture		*image;
	t_pos			*exit;

	exit = get_component((*data)->map, 'E');
	image = (*data)->tiles;
	mlx_image_to_window((*data)->mlx, image->exit_img[0],
		exit->x * TILE, exit->y * TILE);
	free(exit);
}
