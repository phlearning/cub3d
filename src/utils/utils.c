/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:02:52 by pvong             #+#    #+#             */
/*   Updated: 2023/09/25 17:05:51 by pvong            ###   ########.fr       */
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

	if (!map)
		return ;
	ft_printf("=====\n");
	ft_printf("m_no: %s\n", map->m_no);
	ft_printf("m_so: %s\n", map->m_so);
	ft_printf("m_we: %s\n", map->m_we);
	ft_printf("m_ea: %s\n", map->m_ea);
	ft_printf("f_color: %s\n", map->f_color);
	ft_printf("c_color: %s\n", map->c_color);
	ft_printf("=====\n");
	i = -1;
	// ft_printf("map->tab[0]: %s\n", map->tab[0]);
	if (map->tab)
	{
		while (map->tab[++i])
			ft_printf("%s\n", map->tab[i]);
	}
	ft_printf("=====\n");
}

// void	print_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (i)
// }

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
		while (map.tab[++i])
		{
			free(map.tab[i]);
			map.tab[i] = NULL;
		}
		free(map.tab);
		map.tab = NULL;
	}
	i = 0;
	if (map.tmp)
	{
		while (i < map.tab_len && map.tmp[i])
		{
			free(map.tmp[i]);
			map.tmp[i] = NULL;
			i++;
		}	
		free(map.tmp);
		map.tmp = NULL;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	error_exit(char *s, int n)
{
	perror(s);
	exit(n);
}

void	error_exit2(char *s, int n)
{
	write(2, s, ft_strlen(s));
	exit(n);
}