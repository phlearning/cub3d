/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:46:17 by pvong             #+#    #+#             */
/*   Updated: 2023/09/29 14:38:25 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_expose_hook(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, \
		&data->ll, &data->endian);
	return (0);
}

void	ft_hook(t_data *data)
{
	mlx_hook(data->mlx_win, DESTROY_NOTIFY, 0, ft_close, data);
	mlx_hook(data->mlx_win, KEY_PRESS, 0, ft_key_press, data);
	mlx_hook(data->mlx_win, KEY_RELEASE, 0, ft_key_release, data);
	mlx_loop_hook(data->mlx, ft_loop, data);
	mlx_loop(data->mlx);
}

void	ft_update_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->mlx_win);
	ft_expose_hook(data);
	ft_raycasting(data);
}

int	ft_loop(t_data *data)
{
	ft_key_hook(data);
	ft_read_movement(data);
	ft_update_img(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}