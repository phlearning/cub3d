/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/10/08 20:54:08 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init(t_data *data, int ac, char **av)
{
	(void) ac;
	(void) av;
	data->mlx = NULL;
	data->mlx_win = NULL;
	ft_init_mlx(data);
	if (!data->mlx || !data->mlx_win)
		error_exit2("Error: mlx unitialized", 1);
	ft_init_data(data);
	return (0);
}

int	ft_check_extension(char **av, int size_av)
{
	int	res;

	res = 0;
	if (size_av < 5)
		error_exit2("Error: Invalid file", 1);
	if (av[1][size_av - 4] != '.')
		res = 1;
	if (av[1][size_av - 3] != 'c')
		res = 1;
	if (av[1][size_av - 2] != 'u')
		res = 1;
	if (av[1][size_av - 1] != 'b')
		res = 1;
	if (res)
		error_exit2("Error: Wrong extension (.cub)", 1);
	return (res);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_init_mlx(&data);
	ft_init_data(&data);
	if (ac == 2)
	{
		ft_check_extension(av, ft_strlen(av[1]));
		map_parsing(&data, &data.map, av[1]);
	}
	else
		error_exit2("Error: Usage: ./cub3D [map.cub]", 0);
	data.tex = ft_calloc(TEXTURE_NB, sizeof(int *));
	data.t_north = ft_get_texture_img(&data, data.map.m_no, 0);
	data.t_south = ft_get_texture_img(&data, data.map.m_so, 1);
	data.t_east = ft_get_texture_img(&data, data.map.m_ea, 2);
	data.t_west = ft_get_texture_img(&data, data.map.m_we, 3);
	// print_map(&data.map);
	ft_get_player_pos(&data, data.map.tab, data.map.tab_len + 2);
	ft_hook(&data);
	ft_close(&data);
}

