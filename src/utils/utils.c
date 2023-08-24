/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:02:52 by pvong             #+#    #+#             */
/*   Updated: 2023/08/24 14:27:31 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */

char	*ft_strtrim2(char *s1, char *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_trim(set, s1[i]))
		i++;
	while (len > i && s1[len - 1] && ft_trim(set, s1[len - 1]))
		len--;
	str = malloc((len - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
		str[j++] = s1[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

/**
 * Works in conjunction with mlx_hook when closing the window, 
 * we exit the program. It needs to be an int for the mlx_hook.
 * @return int 
 */
int	ft_close(void)
{
	exit(1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/*                                    PRINT                                   */
/* -------------------------------------------------------------------------- */

void	print_map(t_map *map)
{
	int	i;

	ft_printf("=====\n");
	ft_printf("m_no: %s\n", map->m_no);
	ft_printf("m_so: %s\n", map->m_so);
	ft_printf("m_we: %s\n", map->m_we);
	ft_printf("m_ea: %s\n", map->m_ea);
	ft_printf("f_color: %s\n", map->f_color);
	ft_printf("c_color: %s\n", map->c_color);
	ft_printf("=====\n");
	i = -1;
	while (++i < map->size)
		ft_printf("%s\n", map->tab[i]);
	ft_printf("=====\n");
}

/* -------------------------------------------------------------------------- */
/*                                    FREE                                    */
/* -------------------------------------------------------------------------- */

void	free_map(t_map map)
{
	int	i;

	if (map.m_no)
		free(map.m_no);
	if (map.m_so)
		free(map.m_so);
	if (map.m_we)
		free(map.m_we);
	if (map.m_ea)
		free(map.m_ea);
	if (map.f_color)
		free(map.f_color);
	if (map.c_color)
		free(map.c_color);
	i = -1;
	if (map.tab)
	{
		while (++i < map.size)
		{
			free(map.tab[i]);
		}
		free(map.tab);
	}
}