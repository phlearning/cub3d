/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/09/26 15:24:05 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move(int keycode, t_data *data)
{
	int		action;
	double	oldplanex;

	action = 0;
	if (keycode == K_W)
	{
		action++;
		if (ft_compare_set(data->map.tab[(int) (data->p.posx + data->p.dirx * data->p.movespeed)]\
		[(int) data->p.posy], TILE_SET))
			data->p.posx += data->p.dirx * data->p.movespeed;
		if (ft_compare_set(data->map.tab[(int) data->p.posx]\
		[(int) (data->p.posy + data->p.diry * data->p.movespeed)], TILE_SET))
			data->p.posy += data->p.diry * data->p.movespeed;
	}
	if (keycode == K_A)
	{
		action++;
		if (ft_compare_set(data->map.tab[(int) (data->p.posx - data->p.planex * data->p.movespeed)] \
			[(int)data->p.posy], TILE_SET))
			data->p.posx -= data->p.planex * data->p.movespeed;
		if (ft_compare_set(data->map.tab[(int) data->p.posx] \
			[(int)(data->p.posy - data->p.planey * data->p.movespeed)], TILE_SET))
			data->p.posy -= data->p.planey * data->p.movespeed;
	}
	if (keycode == K_D)
	{
		action++;
		if (ft_compare_set(data->map.tab[(int) (data->p.posx + data->p.planex * data->p.movespeed)] \
			[(int)data->p.posy], TILE_SET))
			data->p.posx += data->p.planex * data->p.movespeed;
		if (ft_compare_set(data->map.tab[(int) data->p.posx] \
			[(int)(data->p.posy + data->p.planey * data->p.movespeed)], TILE_SET))
			data->p.posy += data->p.planey * data->p.movespeed;
	}
	if (keycode == K_AR_L)
	{
		action++;
		data->p.old_dirx = data->p.dirx;
		data->p.dirx = data->p.dirx * cos(data->p.rotspeed) - data->p.diry * sin(data->p.rotspeed);
		data->p.diry = data->p.old_dirx * sin(data->p.rotspeed) + data->p.diry * cos(data->p.rotspeed);
		oldplanex = data->p.planex;
		data->p.planex = data->p.planex * cos(data->p.rotspeed) - data->p.planey * sin(data->p.rotspeed);
		data->p.planey = oldplanex * sin(data->p.rotspeed) + data->p.planey * cos(data->p.rotspeed);
	}
	if (keycode == K_S)
	{
		action++;
		if (ft_compare_set(data->map.tab[(int) (data->p.posx - data->p.dirx * data->p.movespeed)]\
			[(int) data->p.posy], TILE_SET))
			data->p.posx -= data->p.dirx * data->p.movespeed;
		if (ft_compare_set(data->map.tab[(int) data->p.posx]\
			[(int) (data->p.posy - data->p.diry * data->p.movespeed)], TILE_SET))
			data->p.posy -= data->p.diry * data->p.movespeed;
	}
	if (keycode == K_AR_R)
	{
		action++;
		data->p.old_dirx = data->p.dirx;
		data->p.dirx = data->p.dirx * cos(-data->p.rotspeed) - data->p.diry * sin(-data->p.rotspeed);
		data->p.diry = data->p.old_dirx * sin(-data->p.rotspeed) + data->p.diry * cos(-data->p.rotspeed);
		oldplanex = data->p.planex;
		data->p.planex = data->p.planex * cos(-data->p.rotspeed) - data->p.planey * sin(-data->p.rotspeed);
		data->p.planey = oldplanex * sin(-data->p.rotspeed) + data->p.planey * cos(-data->p.rotspeed);
	}
	if (action > 0)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_expose_hook(data);
		ft_raycasting(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img , 0, 0);
	}
	return (0);
}

int	main(void)
{
	t_data	data;

	data.p.posx = 2;
	data.p.posy = 2;
	data.p.dirx = 1;
	data.p.diry = 0;
	data.p.planex = 0;
	data.p.planey = -0.66;

	ft_init_mlx(&data);
	// map_parsing(&data.map, "./map/first_map.cub");
	map_parsing(&data.map, "./map/test.cub");
	print_map(&data.map);
	ft_get_player_pos(&data, data.map.tab, data.map.tab_len + 2);
	ft_printf("player_pos: (%d, %d)\n", (int) data.p.posx, (int) data.p.posy);
	ft_printf("player direction: dirx: %d || diry: %d\n", (int) data.p.dirx, (int) data.p.diry);
	// free_map(data.map);
	ft_raycasting(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);

	// HOOKS

	data.p.movespeed = 5.0 / 10;
	data.p.rotspeed = 3.0 / 50;
	ft_hook(&data);
}
