/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:26:41 by jwikiera          #+#    #+#             */
/*   Updated: 2022/11/23 14:26:42 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

typedef struct s_bufobj
{
	char	*buf;
	size_t	buf_size;
	int 	eof;
}       t_bufobj;

void	*gnl_realloc(void *src, size_t src_len, size_t new_len);
size_t  gnl_strlen(const char *s);
void	*gnl_memcpy(void *dest, const void *src, size_t n);

#endif