/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:05:48 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/08 18:00:44 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_and_return(void *memory)
{
	free(memory);
	return (TRUE);
}

int	get_bytes(char *map)
{
	int	fd;
	char	*buffer;
	int	read_byte;
	int	total_bytes;

	total_bytes = 0;
	fd = open (map, O_RDONLY);
	buffer = malloc(100);
	read_byte = read(fd, buffer, 100);
	if (read_byte == 0)
		return (free_and_return(buffer));
	total_bytes += read_byte;
	while (read_byte != 0)
	{
		read_byte = read(fd, buffer, 100);
		total_bytes += read_byte;
	}
	close(fd);
	free(buffer);
	return(total_bytes);
}

char *read_map(char *map)
{
	int		file;
	int		bytes;
	char	*map_b;

	bytes = get_bytes(map) + 1;
	map_b = ft_calloc(sizeof(char), bytes);
	file = open(map, O_RDONLY);
	read(file, map_b, bytes);
	close(file);
	return (map_b);
}