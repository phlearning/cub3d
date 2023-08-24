/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:49:27 by pvong             #+#    #+#             */
/*   Updated: 2023/08/24 13:50:00 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_parsing2(t_map *map, char *map_file)
{
	char	*tmp;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open(map_file, O_RDONLY);
	map->tab = ft_calloc(map->tab_len, sizeof(char *));
	if (!map->tab)
		exit(EXIT_FAILURE);
	map->size = map->tab_len - 1;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		if (i < map->start)
		{
			i++;
			free(tmp);
			continue ;
		}
		tmp = ft_strtrim2(tmp, "\n");
		if (ft_strchr(tmp, '1') || ft_strchr(tmp, '0'))
		{
			map->tab[j++] = ft_strdup(tmp);
		}
		if (tmp)
			free(tmp);
		map->line++;
	}
	close(fd);
	return (0);
}

int	map_parsing(t_map *map, char *map_file)
{
	int		fd;
	char	*tmp;

	map->line = 1;
	map->tab_len = 0;
	map->start = 0;
	fd = open(map_file, O_RDONLY);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		tmp = ft_strtrim2(tmp, "\n");
		if (!ft_strncmp(tmp, "NO", 2))
			map->m_no = ft_strdup(tmp);
		else if (!ft_strncmp(tmp, "SO", 2))
			map->m_so = ft_strdup(tmp);
		else if (!ft_strncmp(tmp, "WE", 2))
			map->m_we = ft_strdup(tmp);
		else if (!ft_strncmp(tmp, "EA", 2))
			map->m_ea = ft_strdup(tmp);
		else if (!ft_strncmp(tmp, "F ", 2))
			map->f_color = ft_strdup(tmp);
		else if (!ft_strncmp(tmp, "C ", 2))
			map->c_color = ft_strdup(tmp);
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
	map_parsing2(map, map_file);
	return (0);
}