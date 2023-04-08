/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:47:41 by misi-moh          #+#    #+#             */
/*   Updated: 2022/12/18 11:35:33 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!small[0])
		return ((char *)(big));
	while (big[i] && i < len)
	{
		while (big[i + j] == small[j])
		{
			j++;
			if (small[j] == '\0' && i + j <= len)
				return ((char *)(big + i));
		}
		j = 0;
		i++;
	}
	return (NULL);
}

	//if (!big || !small)
		//return (NULL);