/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:35:05 by pvong             #+#    #+#             */
/*   Updated: 2023/09/12 20:16:32 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_expose_hook(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->endian);
	return (0);
}

int	ft_control_key(int keycode, t_data *data)
{
	int	action;

	action = 0;
	if (keycode == K_ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	else
	{
		if (keycode >= 0 && keycode != K_ESC)
		{
			action++;
			if (keycode == K_D && data->x <= WIDTH - INCREMENT)
				data->x += 10;
			if (keycode == K_A && data->x >= INCREMENT)
				data->x -= 10;
			if (keycode == K_W && data->y >= INCREMENT)
				data->y -= 10;
			if (keycode == K_S && data->y <= HEIGHT - INCREMENT)
				data->y += 10;
			if (keycode == K_M)
				print_map(&data->map);
		}
	}
	if (action > 0)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_expose_hook(data);
		ft_draw_sq(data, data->x, data->y, 64, 0x0000FF);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	}
	return (0);
}
