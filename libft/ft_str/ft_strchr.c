/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:43:54 by pvong             #+#    #+#             */
/*   Updated: 2022/10/13 10:33:00 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	if (c == '\0' || (char) c == s[i])
		return ((char *) s + i);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = ".Hello";
	char ch = '.';
	char *ret;
	char *ret2;

	ret = strchr(str, ch);
	ret2 = ft_strchr(str,ch);
	printf("Org Ft: String after |%c| is - |%s|\n", ch, ret);
	printf("My Ft: String after |%c| is - |%s|\n", ch, ret2);
	return (0);
}
*/
