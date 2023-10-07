/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:49:27 by pvong             #+#    #+#             */
/*   Updated: 2023/10/07 20:58:53 by pvong            ###   ########.fr       */
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
	rework[0] = ft_calloc(h_len + 1, sizeof(char));
	ft_fill(rework[0], replace, h_len);
	i = 1;
	while (i < v_len - 1)
	{
		rework[i] = ft_calloc(h_len + 1, sizeof(char));
		ft_fill(rework[i], replace, h_len);
		ft_strlcpy(rework[i] + 1, tab[i - 1], h_len);
		ft_change_char(rework[i], ' ', replace);
		ft_fill(rework[i], replace, h_len - 1);
		i++;
	}
	rework[i] = ft_calloc(h_len + 1, sizeof(char));
	ft_fill(rework[i], replace, h_len);
	free_tab(tab);
	return (rework);
}

int	map_parsing2(t_data *data, t_map *map, char *map_file)
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
		error_exit2("Error: len map_parsing\n", EXIT_FAILURE);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_exit("Error: map_parsing2: ", EXIT_FAILURE);
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
		if (ft_is_identifier(data, map, tmp))
		{
			free(tmp);
			continue ;
		}
		if ((ft_strchr(tmp, '1') || ft_strchr(tmp, '0')) && j < map->tab_len)
		{
			map->tab[j] = ft_calloc(len + 2, sizeof(char));
			ft_strlcat(map->tab[j], tmp, len + 1);
			j++;
		}
		if (tmp)
			free(tmp);
	}
	ft_printf("map->line: %d\n", map->line);
	map->tab = ft_rework_tab(map->tab, map->tab_len + 2, len + 2, '-');
	close(fd);
	return (0);
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

void	ft_check_empty_line_in_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!tab[i][0] || tab[i][0] == '\n' || ft_is_only_space(tab[i]))
		{
			free_tab(tab);
			error_exit2("Error: empty line in map", 1);
		}
		i++;
	}
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
	ret_map = ft_calloc(map->tab_len + 1, sizeof(char *));
	if (!ret_map)
		error_exit("Error malloc: ret_map: ", EXIT_FAILURE);
	i = 0;
	j = 0;
	while (1 && j < map->tab_len)
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
		{
			free(tmp);
			tmp = NULL;
		}
	}
	ret_map[j] = NULL;
	if (tmp)
		free(tmp);
	ft_check_empty_line_in_tab(ret_map);
	return (ret_map);
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

int	ft_check_map_vertically(char **tab, char *c)
{
	int	y;
	int	x;
	int	tab_len;
	int	len;

	if (!tab || !tab[0])
		return (1);
	y = 0;
	tab_len = 0;
	while (tab[tab_len])
		tab_len++;
	while (tab[y] && y < tab_len - 1)
	{
		len = ft_strlen(tab[y]);
		x = 0;
		while (x < len)
		{
			if (ft_strncmp(&tab[y][x], c, 1) == 0 && ft_compare_set(tab[y + 1][x], TILE_SET))
				error_exit2("Error: Walls not closed on the top.", 1);
			else if (ft_compare_set(tab[y][x], TILE_SET) && ft_strncmp(&tab[y + 1][x], c, 1) == 0)
				error_exit2("Error: Walls not closed on the bottom.", 1);
			x++;
		}
		y++;
	}
	return (0);
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
			if (ft_strncmp(&tab[y][x], c, 1) == 0 && ft_compare_set(tab[y][x + 1], TILE_SET))
				error_exit2("Error: Walls not closed left.", 1);
			else if (ft_compare_set(tab[y][x], TILE_SET) && ft_strncmp(&tab[y][x + 1], c, 1) == 0)
				error_exit2("Error: Walls not closed right.", 1);
			x++;
		}
		y++;
	}
	return (0);
}

char	*ft_check_and_dup(char *src, char *str, char *message)
{
	char	*ret;

	if (src != NULL)
	{
		ft_printf("Error: %s's duplicate\n", message);
		exit(EXIT_FAILURE);
	}
	ret = ft_strdup(str);
	if (!ret || ret[0] == '\0' || ret[0] == ' ')
		error_exit2("Error: Malloc failed", 1);
	return (ret);
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
				error_exit2("Error: Char not accepted in map", 1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_empty_param(t_data *data, t_map *map)
{
	(void) data;
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
	return (0);
}

int	ft_stock_info(t_data *data, t_map *map, char *line)
{
	char	**tab;

	(void) data;
	map->last_param_line = map->line;
	tab = ft_split(line, ' ');
	if (!tab || !tab[0] || !tab[1])
		error_exit2("Error: empty parameter(s)", 1);
	if (ft_strncmp(line, "NO ", 3) == 0)
		map->m_no = ft_check_and_dup(map->m_no, tab[1], "NO");
	else if (ft_strncmp(line, "EA ", 3) == 0)
		map->m_ea = ft_check_and_dup(map->m_ea, tab[1], "EA");
	else if (ft_strncmp(line, "WE ", 3) == 0)
		map->m_we = ft_check_and_dup(map->m_we, tab[1], "WE");
	else if (ft_strncmp(line, "SO ", 3) == 0)
		map->m_so = ft_check_and_dup(map->m_so, tab[1], "SO");
	else if (ft_strncmp(line, "F ", 2) == 0)
		map->f_color = ft_check_and_dup(map->f_color, tab[1], "F");
	else if (ft_strncmp(line, "C ", 2) == 0)
		map->c_color = ft_check_and_dup(map->c_color, tab[1], "C");
	free_tab(tab);
	return (0);
}

int	ft_is_identifier(t_data *data, t_map *map, char *line)
{
	(void) map;
	(void) data;
	if (!line)
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0 \
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 \
		|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

/**
 * Open the given map file, looks for the texture and map
 * to add them to the struct t_map
 * @param map 
 * @param map_file 
 * @return int 
 */
int	map_parsing(t_data *data, t_map *map, char *map_file)
{
	int		fd;
	char	*tmp;

	(void) data;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_exit3("Error: ", map_file, EXIT_FAILURE);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		tmp = ft_strtrim2(tmp, "\n");
		if (ft_is_identifier(data, map, tmp))
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
	ft_empty_param(data, map);
	if (ft_map_is_last(map))
		error_exit2("Error: map is not last", 0);
	ft_printf("tab_len: %d\n", map->tab_len);
	map->tmp = ft_copy_map(map, map_file);
	print_tab(map->tmp);
	ft_check_for_invalid_char(map->tmp);
	map_parsing2(data, map, map_file);
	// print_map(map);
	ft_check_map_horizontally(map->tab, "-");
	ft_check_map_vertically(map->tab, "-");
	return (0);
}