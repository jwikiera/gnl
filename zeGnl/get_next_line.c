/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:26:32 by jwikiera          #+#    #+#             */
/*   Updated: 2022/11/23 14:26:35 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ioc(char c, char *haystack, size_t haystack_size)
{
	size_t	i;

	i = 0;
	while (i < haystack_size)
	{
		if (haystack[i] == c)
			return (i);
		i ++;
	}
	return (-1);
}

t_bufobj	*get_bufobj(t_bufobj *bufobj)
{
	t_bufobj	*res;

	if (bufobj)
		return bufobj;
	res = malloc(sizeof(*res));
	if (res == NULL)
		return (NULL);
	/*res->buf = malloc(1);
	if (res->buf == NULL)
	{
		free(res);
		return (NULL);
	}*/
	res->buf = 0;
	res->buf_size = 0;
	res->eof = 0;
	return (res);
}

void	*gnl_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*ptr;
	const char		*ptr2;

	if (dest == 0 && src == 0)
	{
		return (dest);
	}
	i = 0;
	ptr = dest;
	ptr2 = src;
	while (i < n)
	{
		*(ptr + i) = *(ptr2 + i);
		i ++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static t_bufobj	*bufobj;
	size_t			readsize;
	char			*res;

	if (fd < 0 || fd >= 4096)
		return (NULL);
	bufobj = get_bufobj(bufobj);
	if (bufobj == NULL)
		return (NULL);
	if (bufobj->eof)
		return (NULL);
	while (ioc('\n', bufobj->buf, bufobj->buf_size) == -1 && !bufobj->eof)
	{
		bufobj->buf = gnl_realloc(bufobj->buf, bufobj->buf_size, bufobj->buf_size + BUFFER_SIZE);
		readsize = read(fd, bufobj->buf + bufobj->buf_size, BUFFER_SIZE);
		if (readsize < 0)
		{
			free(bufobj->buf);
			return (NULL);
		}
		else if (readsize == 0)
		{
			bufobj->eof = 1;
			if (bufobj->buf_size == 0)
				return (NULL);
		}
		else
			bufobj->buf_size += readsize;
	}
	int index_of_nl = ioc('\n', bufobj->buf, bufobj->buf_size);
	if (index_of_nl == -1)
		index_of_nl = bufobj->buf_size;
	res = malloc(index_of_nl + 2 - bufobj->eof);
	if (res == NULL)
		return (NULL);
	gnl_memcpy(res, bufobj->buf, index_of_nl + 1 - bufobj->eof);
	res[index_of_nl + 1 - bufobj->eof] = 0;

	size_t new_buf_size = bufobj->buf_size - (index_of_nl + 1 - bufobj->eof);
	char *tmp = malloc(new_buf_size);
	gnl_memcpy(tmp, bufobj->buf + index_of_nl + 1 - bufobj->eof, new_buf_size);
	free(bufobj->buf);
	bufobj->buf = tmp;
	bufobj->buf_size = new_buf_size;

	return (res);
}
