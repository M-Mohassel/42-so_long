/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:03:34 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/08 17:53:45 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	print_usage(void)
{
	write(1, "Usage: ./Game <name>.ber\n", 25);
	return (TRUE);
}

int	components_error(char *map_string)
{
	write(2, "Missing map components.\n", 24);
	free(map_string);
	return (TRUE);
}

/*int	structure_error(t_map *map)
{
	write(2, "Map is leaking or structure is incorrect.\n", 42);
	free(map->player);
	destroy_structure(map);
	return (TRUE);
}

int	no_valid_path(t_map *map)
{
	write(2, "Map has no valid path.\n", 23);
	destroy_structure(map);
	return (TRUE);
}*/

int	empty_map(char *map_string)
{
	write(2, "Empty map..\n", 12);
	free(map_string);
	return (TRUE);
}
