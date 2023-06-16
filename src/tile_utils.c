/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:08 by misi-moh          #+#    #+#             */
/*   Updated: 2023/06/16 13:29:45 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	delete_tile_textures(t_data **data)
{
	t_texture	*tiles;

	tiles = (*data)->tiles;
	mlx_delete_texture(tiles->floor);
	mlx_delete_texture(tiles->wall);
	mlx_delete_texture(tiles->exit[0]);
	mlx_delete_texture(tiles->exit[1]);
	mlx_delete_texture(tiles->player);
}

void	destroy_movements(t_data **data)
{
	free((*data)->game_movement[0]);
	free((*data)->game_movement[1]);
	free((*data)->game_movement[2]);
	free((*data)->game_movement[3]);
}

void	destroy_tile_structure(t_data **data)
{
	t_texture	*image;

	image = (*data)->tiles;
	free(image);
}
