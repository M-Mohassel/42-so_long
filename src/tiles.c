/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:47 by misi-moh          #+#    #+#             */
/*   Updated: 2023/06/16 13:51:51 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	tiles->player_img = mlx_texture_to_image(mlx, tiles->player);
}

void	init_tile_textures(t_data **data)
{
	t_texture	*tiles;

	(*data)->tiles = (t_texture *)malloc(sizeof(t_texture));
	tiles = (*data)->tiles;
	tiles->floor = mlx_load_png("assets/tiles/floor/floor.png");
	tiles->wall = mlx_load_png("assets/tiles/wall/wall1.png");
	tiles->player = mlx_load_png("assets/player/0.png");
	tiles->exit[0] = mlx_load_png("assets/tiles/other/33.png");
	tiles->exit[1] = mlx_load_png("assets/tiles/other/34.png");
	tiles->exit[2] = 0;
	load_tile_images(data);
	delete_tile_textures(data);
}
