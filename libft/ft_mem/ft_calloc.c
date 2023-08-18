/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:29:35 by pvong             #+#    #+#             */
/*   Updated: 2022/10/13 19:35:01 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// memset
// count * size
// void *memset(void *str, int c, size_t n)

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ptr = ft_memset(ptr, 0, count * size);
	return (ptr);
}
