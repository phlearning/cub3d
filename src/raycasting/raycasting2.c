/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:25:23 by pvong             #+#    #+#             */
/*   Updated: 2023/10/09 16:16:35 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_ray(t_data *d, int x)
{
	d->p.camerax = 2 * x / (double) WIDTH - 1;
	d->p.raydirx = d->p.dirx + d->p.planex * d->p.camerax;
	d->p.raydiry = d->p.diry + d->p.planey * d->p.camerax;
	d->p.mapx = (int) d->p.posx;
	d->p.mapy = (int) d->p.posy;
	if (d->p.raydirx == 0)
		d->p.deltadistx = 1e30;
	else
		d->p.deltadistx = fabs(1 / d->p.raydirx);
	if (d->p.raydiry == 0)
		d->p.deltadisty = 1e30;
	else
		d->p.deltadisty = fabs(1 / d->p.raydiry);
	d->p.hit = 0;
}

void	ft_calc_sidedist(t_data *d)
{
	if (d->p.raydirx < 0)
	{
		d->p.stepx = -1;
		d->p.sidedistx = (d->p.posx - d->p.mapx) * d->p.deltadistx;
	}
	else
	{
		d->p.stepx = 1;
		d->p.sidedistx = (d->p.mapx + 1.0 - d->p.posx) * d->p.deltadistx;
	}
	if (d->p.raydiry < 0)
	{
		d->p.stepy = -1;
		d->p.sidedisty = (d->p.posy - d->p.mapy) * d->p.deltadisty;
	}
	else
	{
		d->p.stepy = 1;
		d->p.sidedisty = (d->p.mapy + 1.0 - d->p.posy) * d->p.deltadisty;
	}
}

double	ft_get_wall_x(t_player p)
{
	double	wall_x;

	if (!p.side)
	{
		wall_x = p.posy + p.perpwalldist * p.raydiry;
		wall_x -= p.mapy;
	}
	else
	{
		wall_x = p.posx + p.perpwalldist * p.raydirx;
		wall_x -= p.mapx;
	}
	return (wall_x);
}
