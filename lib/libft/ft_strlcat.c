/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:11:56 by misi-moh          #+#    #+#             */
/*   Updated: 2022/12/17 17:54:01 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	b;
	size_t	srclen;
	size_t	destlen;

	b = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = destlen;
	if (destlen < size - 1 && size > 0)
	{
		while (src[b] && destlen + b < size - 1)
		{
			dest[i] = src[b];
			i++;
			b++;
		}
		dest[i] = '\0';
	}
	if (destlen >= size)
		destlen = size;
	return (destlen + srclen);
}
