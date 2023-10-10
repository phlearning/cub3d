/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:12:26 by pvong             #+#    #+#             */
/*   Updated: 2023/10/10 11:34:55 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_extension_xpm(char *file)
{
	int	res;
	int	len;

	res = 0;
	len = ft_strlen(file);
	if (len < 5)
		error_exit2("Reason: Unnamed file (.xpm)", 1);
	if (file[len - 4] != '.')
		res++;
	if (file[len - 3] != 'x')
		res++;
	if (file[len - 2] != 'p')
		res++;
	if (file[len - 1] != 'm')
		res++;
	if (res >= 1)
		error_exit2("Reason: Wrong extension (.xpm)", 1);
}

int	ft_check_for_invalid_char(char **tab)
{
	int	x;
	int	y;

	y = 0;
	if (!tab || !tab[0])
		return (1);
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (!ft_compare_set(tab[y][x], TILE_N_WALL))
				error_exit2("Reason: Char not accepted in map", 1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_get_longest_tab_len(char **tab, int tab_len)
{
	int	len;
	int	len2;
	int	i;

	i = -1;
	len = 0;
	if (tab_len <= 0 || !tab)
		return (0);
	while (tab[++i] && i < tab_len - 1)
	{
		len2 = len;
		len = ft_strlen(tab[i]);
		if (len2 > len)
			len = len2;
	}
	return (len);
}

int	ft_is_only_space(char *s)
{
	int	i;
	int	sp_flag;

	i = 0;
	sp_flag = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			sp_flag = 1;
		else
		{
			sp_flag = 0;
			break ;
		}
		i++;
	}
	return (sp_flag);
}
