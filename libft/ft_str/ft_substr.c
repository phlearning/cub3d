/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:04:02 by pvong             #+#    #+#             */
/*   Updated: 2022/10/14 21:12:27 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	l;

	i = 0;
	if (ft_strlen(s) > len)
		l = len;
	else
		l = ft_strlen(s);
	if ((s[0] == '\0' && len != 0) || start > ft_strlen(s))
	{
		ptr = malloc(sizeof(char) * 1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = malloc(sizeof(*s) * (l + 1));
	if (!ptr)
		return (NULL);
	while (s[start] && i < l)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
