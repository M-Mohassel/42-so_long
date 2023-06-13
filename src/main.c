/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:46:38 by misi-moh          #+#    #+#             */
/*   Updated: 2023/06/13 12:12:00 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_and_free(t_data **data)
{
	free_split((*data)->map);
	free((*data)->map_string);
	destroy_movements(data);
	destroy_idle_structure(data);
	destroy_tile_structure(data);
}

void	ft_lstclear_no_free(t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		current = current->next;
		free(*lst);
		*lst = current;
	}
	*lst = NULL;
}

size_t	ft_arrlength(char **string)
{
	size_t	i;	

	i = 0;
	while (string[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (print_usage());
	else
	{
		if (map_has_errors(argv[1]))
			write(1, "Map has errors, exiting..\n", 26);
		else
			game_loop(argv[1]);
	}
	system("leaks so_long");
	system("leaks bonus");
	return (FALSE);
}
