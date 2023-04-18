/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:57:22 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/15 15:05:28 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_pos   *get_player_pos(char **map)
{
    t_pos *position;

    position = (t_pos *)malloc(sizeof(t_pos));
    position->x = -1;
    position->y = 0;
    while(map[++position->x][position->y] != 0)
    {
        while(map[position->x][position->y] != 0)
            if(map[position->x][position->y++] == 'P')
                return (position);
        position->y = 0;
    }
    return (NULL);
}

t_pos   *get_exit_pos(char **map)
{
    t_pos   *position;

    position = (t_pos *)malloc(sizeof(t_pos));
    position->x = -1;
    position->y = 0;
    while (map[++position->x][position->y] != 0)
    {
        while(map[position->x][position->y] != 0)
            if(map[position->x][position->y++] == 'E')
                return (position);
        position->y = 0;
    }
    return (NULL);
}

t_map	*init_structure(char *map_string)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->movements[0] = (t_pos *)malloc(sizeof(t_pos));
	map->movements[1] = (t_pos *)malloc(sizeof(t_pos));
	map->movements[2] = (t_pos *)malloc(sizeof(t_pos));
	map->movements[3] = (t_pos *)malloc(sizeof(t_pos));
	map->movements[4] = NULL;
	map->visited_list = NULL;
	map->double_visited = NULL;
	map->movements[0]->x = 0;
	map->movements[0]->y = -1;
	map->movements[1]->x = 0;
	map->movements[1]->y = 1;
	map->movements[2]->x = 1;
	map->movements[2]->y = 0;
	map->movements[3]->x = -1;
	map->movements[3]->y = 0;
	map->map = ft_split(map_string, '\n');
	map->player = get_player_position(map->map);
	map->exit = get_exit_position(map->map);
	map->map_loop = 0;
	return (map);
}
