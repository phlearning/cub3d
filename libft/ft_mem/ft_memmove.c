/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:10:31 by pvong             #+#    #+#             */
/*   Updated: 2022/10/13 16:06:59 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	d = (char *) dst;
	s = (char *) src;
	if (d > s)
	{	
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{	
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
