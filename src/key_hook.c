/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:35:05 by pvong             #+#    #+#             */
/*   Updated: 2023/09/21 12:54:56 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_control_key(int keycode, t_data *data)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	// ft_move(keycode, data);
	return (0);
}
