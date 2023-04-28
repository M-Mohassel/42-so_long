/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:57:22 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/28 14:31:39 by misi-moh         ###   ########.fr       */
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
	map->player = get_player_pos(map->map);
	map->exit = get_exit_pos(map->map);
	map->map_loop = 0;
	return (map);
}

t_pos   *get_component(char **map, char type)
{
	int			x;
	int			y;
	t_pos	    *exit;

	y = -1;
	exit = (t_pos *)malloc(sizeof(t_pos));
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == type)
			{
				exit->x = x;
				exit->y = y;
				return (exit);
			}
		}
	}
	return (NULL);
}

void	destroy_structure(t_map *map)
{
	free(map->movements[0]);
	free(map->movements[1]);
	free(map->movements[2]);
	free(map->movements[3]);
	free_split(map->map);
	free(map->exit);
	free(map);
}

