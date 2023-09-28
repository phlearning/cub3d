/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/09/28 18:10:35 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// D/M/Y : 28/09/2023
// Corrected map_parsing2 with the length: ft_get_longest_tab_len(char **tab, int tab_len)
// 	instead of ft_get_longest_tab_len(char **tab, int tab_len) - 1
// Created events.c and moved the ft_move() into it
// Changed the events to work with loop_hook

void	ft_init_data(t_data *data)
{
	data->p.movespeed = 0.2;
	data->p.rotspeed = 0.05;
	data->p.forward = 0;
	data->p.backward = 0;
	data->p.left = 0;
	data->p.right = 0;
	data->p.rotate_left = 0;
	data->p.rotate_right = 0;
}

int	main(void)
{
	t_data	data;

	ft_init_mlx(&data);
	ft_init_data(&data);
	// map_parsing(&data.map, "./map/first_map.cub");
	map_parsing(&data.map, "./map/test.cub");
	print_map(&data.map);
	ft_get_player_pos(&data, data.map.tab, data.map.tab_len + 2);
	ft_printf("player_pos: (%d, %d)\n", (int) data.p.posx, (int) data.p.posy);
	ft_printf("player direction: dirx: %d || diry: %d\n", (int) data.p.dirx, (int) data.p.diry);
	// free_map(data.map);

	ft_hook(&data);
}
