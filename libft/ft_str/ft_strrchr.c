/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:45:03 by pvong             #+#    #+#             */
/*   Updated: 2022/10/13 10:35:35 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str);
	if (str == 0)
		return (0);
	while (len > 0)
	{
		if (str[len] == (char) c)
			return ((char *) str + len);
		len--;
	}
	if (c == '\0' || (char) c == str[len])
		return ((char *) str + len);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int len;
	const char str[] = "123.456.789.10";
	const char ch = '.';
	char *ret;
	char *ret2;

	ret = strrchr(str, ch);
	ret2 = ft_strrchr(str, ch);

	printf("Org ft: String after |%c| is - |%s|\n", ch, ret);
	printf("My  ft: String after |%c| is - |%s|\n", ch, ret2);
	return (0);
}
*/
