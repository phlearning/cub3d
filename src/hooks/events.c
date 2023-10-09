/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:10:20 by pvong             #+#    #+#             */
/*   Updated: 2023/10/09 16:43:40 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_collision(t_data *data, double tmp_x, double tmp_y, char **tab)
{
	if (tab[(int)data->p.posy][(int)data->p.posx] == '1' \
		|| tab[(int)data->p.posy][(int)data->p.posx] == '-')
	{
		data->p.posx = tmp_x;
		data->p.posy = tmp_y;
	}
}

void	ft_move_up_down(t_data *d, int dir, char **map)
{
	t_player	p;
	double		speed;
	double		old_posx;
	double		old_posy;

	(void) map;
	p = d->p;
	speed = p.movespeed;
	if (dir)
	{
		old_posx = d->p.posx;
		old_posy = d->p.posy;
		d->p.posx += p.dirx * speed;
		d->p.posy += p.diry * speed;
		ft_check_collision(d, old_posx, old_posy, map);
	}
	else
	{
		old_posx = d->p.posx;
		old_posy = d->p.posy;
		d->p.posx -= p.dirx * speed;
		d->p.posy -= p.diry * speed;
		ft_check_collision(d, old_posx, old_posy, map);
	}
}

void	ft_move_left_right(t_data *d, int dir, char **map)
{
	t_player	p;
	double		speed;
	double		old_posx;
	double		old_posy;

	(void) map;
	p = d->p;
	speed = p.movespeed;
	if (dir)
	{
		old_posx = d->p.posx;
		old_posy = d->p.posy;
		d->p.posx -= p.planex * speed;
		d->p.posy -= p.planey * speed;
		ft_check_collision(d, old_posx, old_posy, map);
	}
	else
	{
		old_posx = d->p.posx;
		old_posy = d->p.posy;
		d->p.posx += p.planex * speed;
		d->p.posy += p.planey * speed;
		ft_check_collision(d, old_posx, old_posy, map);
	}
}

void	ft_rotate_left_right(t_data *d, int dir)
{
	t_player	p;
	double		r_speed;
	double		oldplanex;

	p = d->p;
	if (dir == 0)
		dir = -1;
	r_speed = p.rotspeed * dir;
	d->p.old_dirx = p.dirx;
	d->p.dirx = p.dirx * cos(r_speed) - p.diry * sin(r_speed);
	d->p.diry = d->p.old_dirx * sin(r_speed) + p.diry * cos(r_speed);
	oldplanex = p.planex;
	d->p.planex = p.planex * cos(r_speed) - p.planey * sin(r_speed);
	d->p.planey = oldplanex * sin(r_speed) + p.planey * cos(r_speed);
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
			ft_rotate_left_right(data, 0);
		if (k == K_AR_R)
			ft_rotate_left_right(data, 1);
	}
	if (action > 0)
		ft_update_img(data);
	return (0);
}
