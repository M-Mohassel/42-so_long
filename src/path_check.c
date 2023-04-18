/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:03:25 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/15 16:08:27 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_path(t_map *map)
{
	int			i;
	t_pos	new_pos;

	i = 0;
	mark_map(&map);
	while (map->map_loop == 0)
	{
		while (map->movements[i])
		{
			map->player_moved = 0;
			new_pos = calculate_coords(map->player, map->movements[i++]);
			if (is_valid_coord(new_pos, &map))
			{
				move_player_to_new_pos(&new_pos, &map);
				break ;
			}
		}
		if (!map->player_moved)
			step_back(&map);
		i = 0;
	}
}