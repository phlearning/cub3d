/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:00:20 by pvong             #+#    #+#             */
/*   Updated: 2023/10/09 16:09:28 by pvong            ###   ########.fr       */
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

void	ft_replace_map(t_map *map, int fd, int len)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		if (++i < map->start || ft_is_identifier(tmp))
		{
			free(tmp);
			continue ;
		}
		tmp = ft_strtrim2(tmp, "\n");
		if ((ft_strchr(tmp, '1') || ft_strchr(tmp, '0')) && ++j < map->tab_len)
		{
			map->tab[j] = ft_calloc(len + 2, sizeof(char));
			ft_strlcat(map->tab[j], tmp, len + 1);
		}
		if (tmp)
			free(tmp);
	}
}
