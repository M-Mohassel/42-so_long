/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:10:30 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/15 16:11:03 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	same_coords(t_pos *player, t_pos *exit)
{
	if (player->x == exit->x && player->y == exit->y)
		return (TRUE);
	return (FALSE);
}

int	not_visited(t_pos *position, t_list *head)
{
	t_list	*cursor;

	cursor = head;
	while (cursor)
	{
		if (same_coords(cursor->position, position))
			return (TRUE);
		cursor = cursor->next;
	}
	return (FALSE);
}

int	is_valid_coord(t_pos position, t_map **map)
{
	if (!(not_visited(&position, (*map)->double_visited)
			|| not_visited(&position, (*map)->visited_list)))
		if (not_wall((*map)->map[position.x][position.y])
		&& (*map)->map[position.x][position.y])
			return (TRUE);
	return (FALSE);
}

t_pos	calculate_coords(t_pos *player, t_pos *movement)
{
	t_pos	position;

	position.x = player->x + movement->x;
	position.y = player->y + movement->y;
	return (position);
}
