/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:05:29 by misi-moh          #+#    #+#             */
/*   Updated: 2023/06/20 18:46:34 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_lst	*createnode(int x, int y)
{
	t_lst *newNode = (t_lst *)malloc(sizeof(t_lst));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void insertNode(t_lst	**head, int x, int y) 
{
    t_lst	*newNode = createnode(x, y);

    if (*head == NULL) 
	{
        *head = newNode;
    } else 
	{
        t_lst *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

t_lst *get_list_col(char *str) 
{
    t_lst *head = NULL;
	int i = -1;
    int x = 0;
    int y = 0;

    while (str[++i] != '\0') 
	{
        if (str[x] == 'C') 
		{
            insertNode(&head, x, y);
        }
        if (str[x] == '\n') 
		{
            y++;
            x = 0;
        }
    }
    return head;
}



void	print_lst(t_list *rtl)
{
	t_list *ktl;
	
	ktl = rtl;
	while(rtl->next)
	{
		printf("%d , %d \n", rtl->x, rtl->y);
		rtl = rtl->next;
	}
}

void	init_game_data(t_data **data, char *argv)
{
	int	width;
	int	height;

	(*data)->map_string = read_map(argv);
	(*data)->index = get_collectible_count((*data)->map_string);
	(*data)->list_col = get_list_col((*data)->map_string);
	(*data)->map = ft_split((*data)->map_string, '\n');
	width = TILE * ft_strlen(*(*data)->map);
	height = TILE * ft_arrlength((*data)->map);
	(*data)->mlx = mlx_init(width, height, "so_long", TRUE);
	(*data)->img = mlx_new_image((*data)->mlx, width, height);
	(*data)->collectible_list = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	init_movements(data);
}

void	function_move(t_data *data, t_pos *position)
{
	mlx_image_t		*player;
	mlx_image_t		*player_box;
	static int		move;

	player = data->tiles->player_img;
	player_box = data->player_box;
	if (is_valid_move(data, position))
	{
		player_box->instances[0].y += position->y * TILE;
		player_box->instances[0].x += position->x * TILE;
		player->instances[0].y += position->y * TILE;
		player->instances[0].x += position->x * TILE;
		move++;
		ft_putstr_fd("Player moves: ", 1);
		print_lst(data->collectible_list);
		printf("%d, %d \n",player_box->instances[0].x / TILE ,player_box->instances[0].y / TILE);
		ft_putnbr_fd(move, 1);
		write(1, "\n", 1);
	}
}

void	hook(void *param)
{
	t_data	*data;

	data = param;
	delete_collectible(&data);
	//player_is_on_colectible(&data);
	//check_if_collected_all(data);
	
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data			*data;
	t_list			*head;

	data = param;
	head = data->collectible_list;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		function_move(data, data->game_movement[1]);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		function_move(data, data->game_movement[3]);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		function_move(data, data->game_movement[0]);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		function_move(data, data->game_movement[2]);
	if (player_is_on_exit(&data) && data->index == 0)
	{
		ft_putstr_fd("Game completed!", 1);
		write(1, "\n", 1);
		mlx_close_window(data->mlx);
	}
}

void	game_loop(char *argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	init_game_data(&data, argv);
	draw_map(&data);
	mlx_key_hook(data->mlx, keyhook, data);
	mlx_loop_hook(data->mlx, hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	if (data->collectible_list)
		ft_lstclear_no_free(&data->collectible_list);
	destroy_and_free(&data);
	free(data);
}

