/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:49:27 by pvong             #+#    #+#             */
/*   Updated: 2023/10/02 11:57:38 by pvong            ###   ########.fr       */
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

char	**ft_rework_tab(char **tab, int v_len, int h_len, char replace)
{
	char	**rework;
	int		i;

	rework = ft_calloc(v_len + 1, sizeof(char *));
	if (!rework)
		exit(EXIT_FAILURE);
	rework[0] = ft_calloc(h_len, sizeof(char));
	ft_fill(rework[0], replace, h_len);
	i = 1;
	while (i < v_len - 1)
	{
		rework[i] = ft_calloc(h_len, sizeof(char));
		ft_fill(rework[i], replace, h_len - 1);
		// ft_strlcat(rework[i], tab[i - 1], h_len);
		ft_strlcpy(rework[i] + 1, tab[i - 1], h_len);
		ft_change_char(rework[i], ' ', replace);
		ft_fill(rework[i], replace, h_len - 1);
		i++;
	}
	rework[i] = ft_calloc(h_len, sizeof(char));
	ft_fill(rework[i], replace, h_len);
	free_tab(tab);
	return (rework);
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
	len = ft_get_longest_tab_len(map->tmp, map->tab_len);
	if (len <= 0)
		error_exit2("Error len map_parsing\n", EXIT_FAILURE);
	// free_tab(map->tmp);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_exit("Error fd: map_parsing2: ", EXIT_FAILURE);
	map->tab = ft_calloc(map->tab_len + 1, sizeof(char *));
	if (!map->tab)
		exit(EXIT_FAILURE);
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
			j++;
		}
		if (tmp)
			free(tmp);
		map->line++;
	}
	map->tab = ft_rework_tab(map->tab, map->tab_len + 2, len + 2, '-');
	close(fd);
	return (0);
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
	int		i;
	int		j;
	int		fd;
	char	*tmp;
	char	**ret_map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_exit("Error fd: ", EXIT_FAILURE);
	ret_map = ft_calloc(map->tab_len, sizeof(char *));
	if (!ret_map)
		error_exit("Error malloc: ret_map: ", EXIT_FAILURE);
	i = 0;
	j = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (i < map->start)
		{
			i++;
			free(tmp);
			continue ;
		}
		tmp = ft_strtrim2(tmp, "\n");
		ret_map[j] = ft_strdup(tmp);
		j++;
		if (tmp)
			free(tmp);
	}
	if (tmp)
		free(tmp);
	return (ret_map);
}

/**
 * Open the given map file, looks for the texture and map
 * to add them to the struct t_map
 * @param map 
 * @param map_file 
 * @return int 
 */
int	map_parsing(t_map *map, char *map_file)
{
	int		fd;
	// int		i;
	char	*tmp;

	map->line = 0;
	map->tab_len = 0;
	map->start = 0;
	// i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_exit("Error fd: ", EXIT_FAILURE);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		tmp = ft_strtrim2(tmp, "\n");
		if (!ft_strncmp(tmp, "NO", 2))
			map->m_no = ft_strdup(ft_strchr(tmp, '.'));
		else if (!ft_strncmp(tmp, "SO", 2))
			map->m_so = ft_strdup(ft_strchr(tmp, '.'));
		else if (!ft_strncmp(tmp, "WE", 2))
			map->m_we = ft_strdup(ft_strchr(tmp, '.'));
		else if (!ft_strncmp(tmp, "EA", 2))
			map->m_ea = ft_strdup(ft_strchr(tmp, '.'));
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
	map->tmp = ft_copy_map(map, map_file);
	map_parsing2(map, map_file);
	return (0);
}