/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:49:27 by pvong             #+#    #+#             */
/*   Updated: 2023/08/24 18:33:45 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_change_char(char *s, char c1, char replace_by)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c1)
			s[i] = replace_by;
	}
}

void	ft_fill(char *s, char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		while (s[i] != '\0')
			i++;
		s[i] = c;
		i++;
	}
}

int	ft_get_longest_len(char *file)
{
	int		fd;
	int		len;
	int		tmp_len;
	char	*tmp;

	fd = open(file, O_RDONLY);
	len = 0;
	tmp_len = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp_len = ft_strlen(tmp);
		if (len < tmp_len)
			len = tmp_len;
		free(tmp);
	}
	close(fd);
	if (tmp)
		free(tmp);
	if (len > 0)
		len--;
	ft_printf("len: %d\n", len);
	return (len);
}

int	map_parsing2(t_map *map, char *map_file)
{
	char	*tmp;
	int		fd;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_get_longest_len(map_file);
	fd = open(map_file, O_RDONLY);
	map->tab = ft_calloc(map->tab_len, sizeof(char *));
	if (!map->tab)
		exit(EXIT_FAILURE);
	map->size = map->tab_len;
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
			map->tab[j] = ft_calloc(len + 2, sizeof(char));
			ft_strlcat(map->tab[j], tmp, len + 1);
			ft_change_char(map->tab[j], ' ', 'X');
			ft_fill(map->tab[j], 'X', len + 1);
			j++;
			// map->tab[j++] = ft_strdup(tmp);
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

	map->line = 0;
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