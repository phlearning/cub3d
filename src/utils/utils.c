/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:02:52 by pvong             #+#    #+#             */
/*   Updated: 2023/10/10 11:39:45 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		ft_printf("tab[%d]: %s\n", i, tab[i]);
}

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
	if (map->tab)
	{
		while (map->tab[++i])
			ft_printf("%s\n", map->tab[i]);
	}
	ft_printf("=====\n");
}

int	ft_open(char *file)
{
	int		opened_file;
	char	*str;

	str = ft_strjoin("Reason: ", file);
	opened_file = open(file, O_RDONLY);
	if (opened_file < 0)
	{
		ft_printf("Error\n");
		perror(str);
		free(str);
		str = NULL;
		exit(EXIT_FAILURE);
	}
	free(str);
	str = NULL;
	return (opened_file);
}

void	ft_test_open(char *file)
{
	int	test;

	test = ft_open(file);
	close(test);
}
