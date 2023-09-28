/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:10:20 by pvong             #+#    #+#             */
/*   Updated: 2023/09/28 18:11:19 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_up_down(t_data *d, int dir, char **map)
{
	t_player	p;
	double		speed;

	p = d->p;
	speed = p.movespeed;
	if (dir)
	{
		if (ft_compare_set(map[(int)(p.posx + p.dirx * speed)] \
				[(int)p.posy], TILE_SET))
			d->p.posx += p.dirx * speed;
		if (ft_compare_set(map[(int) p.posx] \
				[(int)(p.posy + p.diry * speed)], TILE_SET))
			d->p.posy += p.diry * speed;
	}
	else
	{
		if (ft_compare_set(map[(int)(p.posx - p.dirx * speed)] \
				[(int)p.posy], TILE_SET))
			d->p.posx -= p.dirx * speed;
		if (ft_compare_set(map[(int) p.posx] \
				[(int)(p.posy - p.diry * speed)], TILE_SET))
			d->p.posy -= p.diry * speed;
	}
}

void	ft_move_left_right(t_data *d, int dir, char **map)
{
	t_player	p;
	double		speed;

	p = d->p;
	speed = p.movespeed;
	if (dir)
	{
		if (ft_compare_set(map[(int)(p.posx - p.planex * speed)] \
				[(int)p.posy], TILE_SET))
			d->p.posx -= p.planex * speed;
		if (ft_compare_set(map[(int)p.posx] \
				[(int)(p.posy - p.planey * speed)], TILE_SET))
			d->p.posy -= p.planey * speed;
	}
	else
	{
		if (ft_compare_set(map[(int)(p.posx + p.planex * speed)] \
				[(int)p.posy], TILE_SET))
			d->p.posx += p.planex * speed;
		if (ft_compare_set(map[(int)p.posx] \
				[(int)(p.posy + p.planey * speed)], TILE_SET))
			d->p.posy += p.planey * speed;
	}
}

void	ft_rotate_left_right(t_data *d, int dir)
{
	t_player	p;
	double		r_speed;
	double		oldplanex;

	p = d->p;
	r_speed = p.rotspeed;
	if (dir)
	{
		d->p.old_dirx = p.dirx;
		d->p.dirx = p.dirx * cos(r_speed) - p.diry * sin(r_speed);
		d->p.diry = d->p.old_dirx * sin(r_speed) + p.diry * cos(r_speed);
		oldplanex = p.planex;
		d->p.planex = p.planex * cos(r_speed) - p.planey * sin(r_speed);
		d->p.planey = oldplanex * sin(r_speed) + p.planey * cos(r_speed);
	}
	else
	{
		d->p.old_dirx = p.dirx;
		d->p.dirx = p.dirx * cos(-r_speed) - p.diry * sin(-r_speed);
		d->p.diry = d->p.old_dirx * sin(-r_speed) + p.diry * cos(-r_speed);
		oldplanex = p.planex;
		d->p.planex = p.planex * cos(-r_speed) - p.planey * sin(-r_speed);
		d->p.planey = oldplanex * sin(-r_speed) + p.planey * cos(-r_speed);
	}
}

int	ft_move(int k, t_data *data)
{
	int		action;

	action = 0;
	if (k == K_W || k == K_S || k == K_A || k == K_D || \
		k == K_AR_L || k == K_AR_R)
	{
		action++;
		if (k == K_W)
			ft_move_up_down(data, 1, data->map.tab);
		else if (k == K_S)
			ft_move_up_down(data, 0, data->map.tab);
		if (k == K_A)
			ft_move_left_right(data, 1, data->map.tab);
		else if (k == K_D)
			ft_move_left_right(data, 0, data->map.tab);
		if (k == K_AR_L)
			ft_rotate_left_right(data, 1);
		if (k == K_AR_R)
			ft_rotate_left_right(data, 0);
	}
	if (action > 0)
		ft_update_img(data);
	return (0);
}

int	ft_read_movement(t_data *d)
{
	if (d->p.forward)
		ft_move_up_down(d, 1, d->map.tab);
	if (d->p.backward)
		ft_move_up_down(d, 0, d->map.tab);
	if (d->p.left)
		ft_move_left_right(d, 1, d->map.tab);
	if (d->p.right)
		ft_move_left_right(d, 0, d->map.tab);
	if (d->p.rotate_left)
		ft_rotate_left_right(d, 1);
	if (d->p.rotate_right)
		ft_rotate_left_right(d, 0);
	return (0);
}
