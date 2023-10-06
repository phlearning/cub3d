/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkukaqi <bkukaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/10/06 11:17:07 by bkukaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_init_mlx(&data);
	ft_init_data(&data);
	// Temporary
	if (ac == 2)
		map_parsing(&data.map, av[1]);
	data.tex = ft_calloc(TEXTURE_NB, sizeof(int *));
	data.t_north = ft_get_texture_img(&data, data.map.m_no, 0);
	data.t_south = ft_get_texture_img(&data, data.map.m_so, 1);
	data.t_east = ft_get_texture_img(&data, data.map.m_ea, 2);
	data.t_west = ft_get_texture_img(&data, data.map.m_we, 3);
	// 
	// map_parsing(&data.map, "./map/first_map.cub");
	// parsing_param(data);
	print_map(&data.map);
	ft_get_player_pos(&data, data.map.tab, data.map.tab_len + 2);
	// free_map(data.map);

	ft_hook(&data);
	ft_close(&data);
}

// int	main(void)
// {
// 	t_data	data;
// 	// char	**tab;

// 	// tab = ft_split("hello        world\n", ' ');
// 	// print_tab(tab);
// 	ft_init_mlx(&data);
// 	ft_init_data(&data);
// 	data.tex = ft_calloc(TEXTURE_NB, sizeof(int *));
// 	data.t_north = ft_calloc(1, sizeof(t_texture));
// 	data.t_south = ft_calloc(1, sizeof(t_texture));
// 	data.t_east = ft_calloc(1, sizeof(t_texture));
// 	data.t_west = ft_calloc(1, sizeof(t_texture));
// 	// data.t_north = ft_get_texture_img(&data, "./textures/xpm/bluestone.xpm", 0);
// 	// data.t_south = ft_get_texture_img(&data, "./textures/xpm/colorstone.xpm", 1);
// 	// data.t_east = ft_get_texture_img(&data, "./textures/xpm/greystone.xpm", 2);
// 	// data.t_west = ft_get_texture_img(&data, "./textures/xpm/mossy.xpm", 3);
// 	map_parsing(&data.map, "./map/test.cub");
// 	print_map(&data.map);
// 	ft_close(&data);
// 	return (0);
// }