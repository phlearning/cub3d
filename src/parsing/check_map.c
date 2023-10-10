/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:02 by pvong             #+#    #+#             */
/*   Updated: 2023/10/10 11:36:52 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_check_and_dup(char *src, char *file_name, char *message, int is_tex)
{
	char	*ret;

	if (src != NULL)
	{
		ft_printf("Error\n");
		ft_printf("Reason: %s's duplicate\n", message);
		exit(EXIT_FAILURE);
	}
	if (is_tex)
		ft_check_extension_xpm(file_name);
	ret = ft_strdup(file_name);
	if (!ret || ret[0] == '\0' || ret[0] == ' ')
		error_exit2("Reason: Malloc failed", 1);
	return (ret);
}

/**
 * Check if the map is locked between walls horizontally 
 * by checking that there is no 0 and '-' near each other;
 * @param tab 		the map
 * @param l_len 	the longest len
 * @param c 		the border of the map
 * @return int 
 */
int	ft_check_map_horizontally(char **tab, char *c)
{
	int	y;
	int	x;
	int	len;

	if (!tab || !tab[0])
		return (1);
	y = 0;
	while (tab[y])
	{
		len = ft_strlen(tab[y]);
		x = 0;
		while (x < len - 1)
		{
			if (ft_strncmp(&tab[y][x], c, 1) == 0 \
				&& ft_compare_set(tab[y][x + 1], TILE_SET))
				error_exit2("Reason: Walls not closed left.", 1);
			else if (ft_compare_set(tab[y][x], TILE_SET) \
				&& ft_strncmp(&tab[y][x + 1], c, 1) == 0)
				error_exit2("Reason: Walls not closed right.", 1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_check_map_vertically(char **tab, char *c)
{
	int	y;
	int	x;
	int	tab_len;
	int	len;

	if (!tab || !tab[0])
		return ;
	y = -1;
	tab_len = 0;
	while (tab[tab_len])
		tab_len++;
	while (++y < tab_len - 1 && tab[y])
	{
		len = ft_strlen(tab[y]);
		x = -1;
		while (++x < len)
		{
			if (ft_strncmp(&tab[y][x], c, 1) == 0 \
				&& ft_compare_set(tab[y + 1][x], TILE_SET))
				error_exit2("Reason: Walls not closed on the top.", 1);
			else if (ft_compare_set(tab[y][x], TILE_SET) \
				&& ft_strncmp(&tab[y + 1][x], c, 1) == 0)
				error_exit2("Reason: Walls not closed on the bottom.", 1);
		}
	}
}

/**
 * Check if the end line of the map correspond to the last line
 * of the .cub file.
 * 1 -> Wrong end and enter the exit condition.
 * 0 -> Correspond end line to the last line of the doc 
 *  and continue the parsing
 * @param map 
 * @return int 
 */
int	ft_map_is_last(t_map *map)
{
	if (map->start + map->tab_len == map->line \
	|| map->start > map->last_param_line)
		return (0);
	return (1);
}

void	ft_check_empty_line_in_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!tab[i][0] || tab[i][0] == '\n' || ft_is_only_space(tab[i]))
		{
			free_tab(tab);
			error_exit2("Reason: empty line in map", 1);
		}
		i++;
	}
}
