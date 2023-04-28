/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:08 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/28 13:16:20 by misi-moh         ###   ########.fr       */
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
}

void	delete_idle_textures(t_data **data)
{
	t_idle	*idle;

	idle = (*data)->idle;
	mlx_delete_texture(idle->right[0]);
	mlx_delete_texture(idle->right[1]);
	mlx_delete_texture(idle->right[2]);
	mlx_delete_texture(idle->right[3]);
	mlx_delete_texture(idle->right[4]);
	mlx_delete_texture(idle->right[5]);
	mlx_delete_texture(idle->right[6]);
	mlx_delete_texture(idle->right[7]);
}

void	destroy_movements(t_data **data)
{
	free((*data)->enemy_movement[0]);
	free((*data)->enemy_movement[1]);
	free((*data)->enemy_movement[2]);
	free((*data)->enemy_movement[3]);
}

void	destroy_idle_structure(t_data **data)
{
	t_idle	*image;

	image = (*data)->idle;
	free(image);
}

void	destroy_tile_structure(t_data **data)
{
	t_texture	*image;

	image = (*data)->tiles;
	free(image);
}
