/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:45:03 by pvong             #+#    #+#             */
/*   Updated: 2023/10/07 22:02:20 by pvong            ###   ########.fr       */
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
