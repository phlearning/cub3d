/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:50:50 by pvong             #+#    #+#             */
/*   Updated: 2023/03/08 14:53:04 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0 || (s1 == 0 && s2 == 0))
		return (0);
	while (i < n && s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	if (i == n)
		i--;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*
#include <stdio.h>

int	main (void) 
{
	char	str1[15];
	char	str2[15];
	int	ret;
	int	ret2;
	int	n;

	n = 1;
	strcpy(str1, "a");
	strcpy(str2, "A");

	ret = strncmp(str1, str2, n);
	ret2 = ft_strncmp(str1, str2, n);

	printf("Org ft: %d\n", ret);
	printf("My ft: %d\n", ret2);
	return(0);
}
*/
