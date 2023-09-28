/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:35:05 by pvong             #+#    #+#             */
/*   Updated: 2023/09/28 18:07:45 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		ft_close(data);
	ft_move_press(keycode, data);
	return (0);
}

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		ft_close(data);
	ft_move_release(keycode, data);
	return (0);
}

int	ft_move_press(int k, t_data *d)
{
	if (k == K_W)
		return (d->p.forward = 1, 0);
	else if (k == K_S)
		return (d->p.backward = 1, 0);
	else if (k == K_A)
		return (d->p.left = 1, 0);
	else if (k == K_D)
		return (d->p.right = 1, 0);
	else if (k == K_AR_L)
		return (d->p.rotate_left = 1, 0);
	else if (k == K_AR_R)
		return (d->p.rotate_right = 1, 0);
	return (0);
}

int	ft_move_release(int k, t_data *d)
{
	if (k == K_W)
		return (d->p.forward = 0, 0);
	else if (k == K_S)
		return (d->p.backward = 0, 0);
	else if (k == K_A)
		return (d->p.left = 0, 0);
	else if (k == K_D)
		return (d->p.right = 0, 0);
	else if (k == K_AR_L)
		return (d->p.rotate_left = 0, 0);
	else if (k == K_AR_R)
		return (d->p.rotate_right = 0, 0);
	return (0);
}

void	ft_key_hook(t_data *data)
{
	mlx_hook(data->mlx_win, DESTROY_NOTIFY, 0, ft_close, data);
	mlx_hook(data->mlx_win, KEY_PRESS, 0, ft_key_press, data);
	mlx_hook(data->mlx_win, KEY_RELEASE, 0, ft_key_release, data);
}