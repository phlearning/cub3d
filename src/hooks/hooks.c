/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:46:17 by pvong             #+#    #+#             */
/*   Updated: 2023/09/21 16:19:15 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_expose_hook(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->endian);
	return (0);
}

void	ft_hook(t_data *data)
{
	mlx_hook(data->mlx_win, DESTROY_NOTIFY, 0, ft_close, data);
	mlx_hook(data->mlx_win, KEY_PRESS, 0, ft_move, data);
	mlx_key_hook(data->mlx_win, ft_control_key, data);
	mlx_loop(data->mlx);
}