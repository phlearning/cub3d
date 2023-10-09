/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:29 by pvong             #+#    #+#             */
/*   Updated: 2023/10/09 16:16:37 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_advance_ray_step(t_data *d)
{
	while (d->p.hit == 0)
	{
		if (d->p.sidedistx < d->p.sidedisty)
		{
			d->p.sidedistx += d->p.deltadistx;
			d->p.mapx += d->p.stepx;
			d->p.side = 0;
		}
		else
		{
			d->p.sidedisty += d->p.deltadisty;
			d->p.mapy += d->p.stepy;
			d->p.side = 1;
		}
		if (!ft_compare_set(d->map.tab[d->p.mapy][d->p.mapx], TILE_SET))
			d->p.hit = 1;
	}
}

void	ft_calc_drawing_range(t_data *d)
{
	if (d->p.side == 0)
			d->p.perpwalldist = (d->p.sidedistx - d->p.deltadistx);
	else
		d->p.perpwalldist = (d->p.sidedisty - d->p.deltadisty);
	d->p.lineheight = (int)(HEIGHT / d->p.perpwalldist);
	d->p.drawstart = -(d->p.lineheight) / 2 + HEIGHT / 2;
	if (d->p.drawstart < 0)
		d->p.drawstart = 0;
	d->p.drawend = d->p.lineheight / 2 + HEIGHT / 2;
	if (d->p.drawend >= HEIGHT)
		d->p.drawend = HEIGHT - 1;
}

void	ft_raycasting(t_data *d)
{
	int	x;

	x = 0;
	ft_render_ceilling_floor(d);
	while (x < WIDTH)
	{
		ft_init_ray(d, x);
		ft_calc_sidedist(d);
		ft_advance_ray_step(d);
		ft_calc_drawing_range(d);
		ft_get_wall_dir(d);
		ft_apply_texture(d, &d->p, x, d->p.wall_dir);
		x++;
	}
}
