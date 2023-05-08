/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:03:25 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/29 14:01:37 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mark_map(t_map **map)
{
	(*map)->map[(*map)->player->x][(*map)->player->y] = 'X';
	(*map)->player_moved = 1;
}

void	copy_coords(t_pos **destination, t_pos **source)
{
	(*destination)->x = (*source)->x;
	(*destination)->y = (*source)->y;
}

void	move_player_to_new_pos(t_pos *new_pos, t_map **map)
{
	t_pos	*node;

	node = (t_pos *)malloc(sizeof(t_pos));
	copy_coords(&node, &(*map)->player);
	ft_lstadd_front(&(*map)->visited_list, ft_lstnew(node));
	copy_coords(&(*map)->player, &new_pos);
	mark_map(map);
}

void	step_back(t_map **map)
{
	t_list		*temp;

	ft_lstadd_front(&(*map)->double_visited, ft_lstnew((*map)->player));
	if (!(*map)->visited_list)
	{
		(*map)->map_loop = 1;
		return ;
	}
	temp = (*map)->visited_list;
	(*map)->player = (*map)->visited_list->position;
	(*map)->visited_list = (*map)->visited_list->next;
	temp->next = NULL;
	free(temp);
}

void	check_map_path(t_map *map)
{
	int			i;
	t_pos		new_pos;

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
