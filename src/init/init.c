/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:43:48 by pvong             #+#    #+#             */
/*   Updated: 2023/10/07 19:48:58 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Hello world!");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->endian);
}

void	ft_init_data(t_data *data)
{
	data->p.movespeed = 0.2;
	data->p.rotspeed = 0.05;
	data->p.forward = FALSE;
	data->p.backward = FALSE;
	data->p.left = FALSE;
	data->p.right = FALSE;
	data->p.rotate_left = FALSE;
	data->p.rotate_right = FALSE;
	data->map.line = 0;
	data->map.tab_len = 0;
	data->map.start = 0;
	data->map.last_param_line = 0;
	data->map.tmp = NULL;
	data->map.tab = NULL;
	data->map.m_no = NULL;
	data->map.m_ea = NULL;
	data->map.m_we = NULL;
	data->map.m_so = NULL;
	data->map.f_color = NULL;
	data->map.c_color = NULL;
}
