/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:43:48 by pvong             #+#    #+#             */
/*   Updated: 2023/10/05 13:13:04 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_data *data)
{
	data->relative_path = "./test.xpm";
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Hello world!");
	// data->img = mlx_xpm_file_to_image(data->mlx, data->relative_path, &data->img_width, &data->img_height);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->endian);
}

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
