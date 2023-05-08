/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:05:15 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/29 14:07:05 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_handling(char errnum)
{
	if (!errnum)
		write(2, "Invalid map name.", 17);
	else
		ft_putstr_fd(strerror(errnum), 2);
	write(2, "\n", 1);
	return (TRUE);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != 0)
		free(split[i]);
	free(split);
}

int	not_valid_map_name(char *filename)
{
	int	len;
	int	file;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (error_handling(errno));
	close(file);
	len = ft_strlen(filename);
	if (ft_strncmp(filename + (len - 4), ".ber\0", 5))
		return (error_handling(0));
	return (FALSE);
}
