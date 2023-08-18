/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:02:02 by pvong             #+#    #+#             */
/*   Updated: 2022/10/12 16:44:39 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0 || src == 0)
		return (len);
	while (src[i] && i < len && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
/*
#include <stdio.h>

int	main(void)
{
	char	source[] = "Hello World";
	char	destination[0];
	char	source2[] = "Hello World";
	char	destination2[0];
	int		dsize;

	dsize = 100;
	printf("Source : %s\n",source);
//	printf("Strlcpy:    %lu\n", strlcpy(destination, source, dsize));
	printf("ft_strlcpy: %lu\n", ft_strlcpy(destination, source, dsize));
	printf("Source after: %s\n",source);
	printf("Destination after: %s\n",destination);
	return (0);
}
*/
