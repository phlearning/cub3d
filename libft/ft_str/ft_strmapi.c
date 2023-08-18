/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:51:58 by pvong             #+#    #+#             */
/*   Updated: 2022/10/19 13:24:05 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ft;
	unsigned int	i;

	i = 0;
	ft = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ft)
		return (NULL);
	while (s[i])
	{
		ft[i] = s[i];
		ft[i] = f(i, s[i]);
		i++;
	}
	ft[i] = '\0';
	return (ft);
}
