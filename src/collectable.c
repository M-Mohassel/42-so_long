/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:05:57 by misi-moh          #+#    #+#             */
/*   Updated: 2023/06/28 13:37:55 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_collectible_count(char *map)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (map[++i])
		if (map[i] == 'C')
			count++;
	return (count);
}

void	free_and_delete_image(t_data **data, mlx_image_t *image, t_list *head)
{
	t_list	*temp;

	temp = head->next;
	mlx_delete_image((*data)->mlx, image);
	free(temp);
}

void	delete_collectible(t_data **data)
{
	t_list	*tmp;
	t_list	*prev;
	int		posy;
	int		posx;

	posx = (*data)->player_box->instances[0].x / TILE;
	posy = (*data)->player_box->instances[0].y / TILE;
	tmp = (*data)->collectible_list;
	if (tmp->x == posx && tmp->y == posy)
	{
		(*data)->collectible_list = tmp->next;
		mlx_delete_image((*data)->mlx, tmp->position);
		free(tmp);
		return ;
	}
	while (tmp != NULL && !(tmp->x == posx && tmp->y == posy))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	mlx_delete_image((*data)->mlx, tmp->position);
	free(tmp);
}

void	player_is_on_colectible(t_data **data)
{
	mlx_instance_t	*player;
	int				posx;
	int				posy;

	player = (*data)->player_box->instances;
	posx = player[0].x / TILE;
	posy = player[0].y / TILE;
	if ((*data)->map[posy][posx] == 'C')
	{
		(*data)->map[posy][posx] = '0';
		delete_collectible(data);
	}
}

void	check_if_collected_all(t_data *data)
{
	mlx_image_t		*exit_locked;
	mlx_image_t		*exit_unlocked;

	if (!data->collectible_list)
	{
		exit_locked = data->tiles->exit_img[0];
		exit_unlocked = data->tiles->exit_img[1];
		ft_memcpy(exit_locked->pixels, exit_unlocked->pixels,
			TILE * TILE * 4);
	}
}
