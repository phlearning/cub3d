/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:13:08 by pvong             #+#    #+#             */
/*   Updated: 2022/10/13 17:28:36 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (n <= 0 || (s1 == 0 && s2 == 0))
		return (0);
	while (i < n && str1[i] == str2[i])
		i++;
	if (i == n)
		i--;
	return ((unsigned char) str1[i] - (unsigned char) str2[i]);
}
