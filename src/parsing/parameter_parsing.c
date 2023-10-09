/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:24:08 by pvong             #+#    #+#             */
/*   Updated: 2023/10/09 16:30:12 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_empty_param(t_map *map)
{
	if (map->line < 6)
		error_exit2("Error: Invalid .cub file", 1);
	if (!map->m_no || map->m_no[0] == '\0' || map->m_no[0] == ' ')
		error_exit2("Error: NO's empty", 1);
	if (!map->m_ea || map->m_ea[0] == '\0' || map->m_ea[0] == ' ')
		error_exit2("Error: EA's empty", 1);
	if (!map->m_we || map->m_we[0] == '\0' || map->m_we[0] == ' ')
		error_exit2("Error: WE's empty", 1);
	if (!map->m_so || map->m_so[0] == '\0' || map->m_so[0] == ' ')
		error_exit2("Error: SO's empty", 1);
	if (!map->f_color || map->f_color[0] == '\0' || map->f_color[0] == ' ')
		error_exit2("Error: F's empty", 1);
	if (!map->c_color || map->c_color[0] == '\0' || map->c_color[0] == ' ')
		error_exit2("Error: C's empty", 1);
}

int	ft_is_identifier(char *line)
{
	if (!line)
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0 \
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 \
		|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

int	ft_stock_info(t_data *data, t_map *map, char *line)
{
	char	**tab;

	(void) data;
	map->last_param_line = map->line;
	tab = ft_split(line, ' ');
	if (!tab || !tab[0] || !tab[1] || tab[2])
		error_exit2("Error: wrong parameter(s)", 1);
	if (ft_strncmp(line, "NO ", 3) == 0)
		map->m_no = ft_check_and_dup(map->m_no, tab[1], "NO", 1);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		map->m_ea = ft_check_and_dup(map->m_ea, tab[1], "EA", 1);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		map->m_we = ft_check_and_dup(map->m_we, tab[1], "WE", 1);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		map->m_so = ft_check_and_dup(map->m_so, tab[1], "SO", 1);
	else if (ft_strncmp(line, "F ", 2) == 0)
		map->f_color = ft_check_and_dup(map->f_color, tab[1], "F", 0);
	else if (ft_strncmp(line, "C ", 2) == 0)
		map->c_color = ft_check_and_dup(map->c_color, tab[1], "C", 0);
	free_tab(tab);
	return (0);
}
