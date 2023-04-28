/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:47 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/28 13:18:46 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_idle_images(t_data **data)
{
	t_idle	*idle;

	idle = (*data)->idle;
	idle->right_idle[0] = mlx_texture_to_image((*data)->mlx, idle->right[0]);
	idle->right_idle[1] = mlx_texture_to_image((*data)->mlx, idle->right[1]);
	idle->right_idle[2] = mlx_texture_to_image((*data)->mlx, idle->right[2]);
	idle->right_idle[3] = mlx_texture_to_image((*data)->mlx, idle->right[3]);
	idle->right_idle[4] = mlx_texture_to_image((*data)->mlx, idle->right[4]);
	idle->right_idle[5] = mlx_texture_to_image((*data)->mlx, idle->right[5]);
	idle->right_idle[6] = mlx_texture_to_image((*data)->mlx, idle->right[6]);
	idle->right_idle[7] = mlx_texture_to_image((*data)->mlx, idle->right[7]);
	idle->right_idle[8] = 0;
	idle->idle = mlx_texture_to_image((*data)->mlx, idle->right[0]);
}

void	load_tile_images(t_data **data)
{
	t_texture	*tiles;
	mlx_t		*mlx;

	mlx = (*data)->mlx;
	tiles = (*data)->tiles;
	tiles->floor_img = mlx_texture_to_image(mlx, tiles->floor);
	tiles->wall_img = mlx_texture_to_image(mlx, tiles->wall);
	tiles->exit_img[0] = mlx_texture_to_image(mlx, tiles->exit[0]);
	tiles->exit_img[1] = mlx_texture_to_image(mlx, tiles->exit[1]);
}

void	init_tile_textures(t_data **data)
{
	t_texture	*tiles;

	(*data)->tiles = (t_texture *)malloc(sizeof(t_texture));
	tiles = (*data)->tiles;
	tiles->floor = mlx_load_png("assets/tiles/floor/0.png");
	tiles->wall = mlx_load_png("assets/tiles/wall/0.png");
	tiles->exit[0] = mlx_load_png("assets/tiles/other/33.png");
	tiles->exit[1] = mlx_load_png("assets/tiles/other/34.png");
	tiles->exit[2] = 0;
	load_tile_images(data);
	delete_tile_textures(data);
}

void	init_idle_texture(t_data **data)
{
	t_idle	*idle;

	(*data)->idle = (t_idle *)malloc(sizeof(t_idle));
	idle = (*data)->idle;
	idle->right[0] = mlx_load_png("assets/player/idle/right/0.png");
	idle->right[1] = mlx_load_png("assets/player/idle/right/1.png");
	idle->right[2] = mlx_load_png("assets/player/idle/right/2.png");
	idle->right[3] = mlx_load_png("assets/player/idle/right/3.png");
	idle->right[4] = mlx_load_png("assets/player/idle/right/4.png");
	idle->right[5] = mlx_load_png("assets/player/idle/right/5.png");
	idle->right[6] = mlx_load_png("assets/player/idle/right/6.png");
	idle->right[7] = mlx_load_png("assets/player/idle/right/7.png");
	idle->right[8] = 0;
	load_idle_images(data);
	delete_idle_textures(data);
}
