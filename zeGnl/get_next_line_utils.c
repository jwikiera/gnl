/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:26:51 by jwikiera          #+#    #+#             */
/*   Updated: 2022/11/23 14:26:53 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_realloc(void *src, size_t src_len, size_t new_len)
{
	size_t	i;
	char	*ptr;
	char	*dest;

	dest = malloc(new_len);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < new_len)
	{
		*(dest + i) = 0;
		i ++;
	}
	i = 0;
	ptr = src;
	while (i < src_len)
	{
		*(dest + i) = *(ptr + i);
		i ++;
	}
	free(src);
	return (dest);
}
