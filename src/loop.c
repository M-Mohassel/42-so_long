/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:05:29 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/08 18:04:44 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void init_game_data (t_data **data, char *argv)
{
	int	width;
	int	height;

	(*data)->map_string = read_map(argv);
	(*data)->map = ft_split((*data)->map_string, '\n');
	width = TILE * ft_strlen(*(*data)->map);
	height = TILE * ft_arrlength((*data)->map);
	(*data)->mlx = mlx_init(width, height, "so_long", true);
	(*data)->img = mlx_new_image((*data)->mlx, width, height);
	//(*data)->collectible_list = NULL;
	//(*data)->enemy_list = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	//init_movements(data);
}

void game_loop (char *argv)
{
	t_data	*data;

	init_game_data(&data, argv);
    draw_map(&data);
}