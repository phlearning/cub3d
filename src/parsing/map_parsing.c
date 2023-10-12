/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:49:27 by pvong             #+#    #+#             */
/*   Updated: 2023/10/12 11:33:06 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map(t_map *map, char *map_file)
{
	ft_empty_param(map);
	if (ft_map_is_last(map))
		error_exit2("Reason: map is not last", 0);
	map->tmp = ft_copy_map(map, map_file);
	ft_check_for_invalid_char(map->tmp);
	ft_check_map_horizontally(map->tab, "-");
	ft_check_map_vertically(map->tab, "-");
}

void	map_parsing2(t_map *map, char *map_file)
{
	int		fd;
	int		len;

	len = ft_get_longest_tab_len(map->tmp, map->tab_len);
	if (len <= 0)
		error_exit2("Reason: len map_parsing", EXIT_FAILURE);
	fd = ft_open(map_file);
	map->tab = ft_calloc(map->tab_len + 1, sizeof(char *));
	if (!map->tab)
		error_exit2("Reason: map->tab malloc", EXIT_FAILURE);
	ft_replace_map(map, fd, len);
	map->tab = ft_rework_tab(map->tab, map->tab_len + 2, len + 2, '-');
	close(fd);
}

/**
 * Open the given map file, looks for the texture and map
 * to add them to the struct t_map
 * @param map 
 * @param map_file 
 * @return int 
 */
void	map_parsing(t_data *data, t_map *map, char *map_file)
{
	int		fd;
	char	*tmp;

	fd = ft_open(map_file);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		tmp = ft_strtrim2(tmp, "\n");
		if (ft_is_identifier(tmp))
			ft_stock_info(data, map, tmp);
		else if (ft_strchr(tmp, '1') || ft_strchr(tmp, '0'))
		{
			if (map->start == 0)
				map->start = map->line;
			map->tab_len++;
		}
		if (tmp)
			free(tmp);
		map->line++;
	}
	close(fd);
	ft_check_map(map, map_file);
}
