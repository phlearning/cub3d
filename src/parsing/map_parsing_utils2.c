/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:49:56 by pvong             #+#    #+#             */
/*   Updated: 2023/10/10 11:36:09 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_copy_gnl(t_map *map, char **ret_map, int fd)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (1 && j < map->tab_len)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (++i < map->start)
		{
			free(tmp);
			continue ;
		}
		tmp = ft_strtrim2(tmp, "\n");
		ret_map[j] = ft_strdup(tmp);
		j++;
		free(tmp);
	}
	ret_map[j] = NULL;
}

/**
 * This function needs the start line given in map->start.
 * It open the files and read the line until the given start line.
 * Then it copies the line unto the tab.
 * @param map
 * @param map_file 
 * @return char** 
 */
char	**ft_copy_map(t_map *map, char *map_file)
{
	int		fd;
	char	**ret_map;

	fd = ft_open(map_file);
	ret_map = ft_calloc(map->tab_len + 1, sizeof(char *));
	if (!ret_map)
		error_exit("Reason: ret_map: ", EXIT_FAILURE);
	ft_copy_gnl(map, ret_map, fd);
	ft_check_empty_line_in_tab(ret_map);
	return (ret_map);
}
