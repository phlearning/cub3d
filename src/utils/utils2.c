/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:58:04 by pvong             #+#    #+#             */
/*   Updated: 2023/10/10 11:35:40 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_extension(char **av, int size_av)
{
	int	res;

	res = 0;
	if (size_av < 5)
		error_exit2("Reason: Invalid file", 1);
	if (av[1][size_av - 4] != '.')
		res = 1;
	if (av[1][size_av - 3] != 'c')
		res = 1;
	if (av[1][size_av - 2] != 'u')
		res = 1;
	if (av[1][size_av - 1] != 'b')
		res = 1;
	if (res)
		error_exit2("Reason: Wrong extension (.cub)", 1);
	return (res);
}

/**
 * To compare the char in the map to the tile_set "0NSEW"
 * @param n 
 * @param s 
 * @return int 
 */
int	ft_compare_set(int n, char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (n == (int) s[i])
			return (1);
	}
	return (0);
}

char	*ft_strtrim2(char *s1, char *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_trim(set, s1[i]))
		i++;
	while (len > i && s1[len - 1] && ft_trim(set, s1[len - 1]))
		len--;
	str = malloc((len - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
		str[j++] = s1[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}
