/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:29 by pvong             #+#    #+#             */
/*   Updated: 2023/10/07 21:06:04 by pvong            ###   ########.fr       */
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
		if (!ft_compare_set(d->map.tab[d->p.mapx][d->p.mapy], TILE_SET))
			d->p.hit = 1;
	}
}

void	ft_calc_drawing_range(t_data *d)
{
	if (d->p.side == 0)
			d->p.perpwalldist = (d->p.sidedistx - d->p.deltadistx);
	else
		d->p.perpwalldist = (d->p.sidedisty - d->p.deltadisty);
	d->p.lineheight = (int) (HEIGHT / d->p.perpwalldist);
	d->p.drawstart = -(d->p.lineheight) / 2 + HEIGHT / 2;
	if (d->p.drawstart < 0)
		d->p.drawstart = 0;
	d->p.drawend = d->p.lineheight / 2 + HEIGHT / 2;
	if (d->p.drawend >= HEIGHT)
		d->p.drawend = HEIGHT - 1;
}

void	ft_get_wall_dir(t_data *d)
{
	int		side;
	double	ray_dir_y;
	double	ray_dir_x;

	side = d->p.side;
	ray_dir_x = d->p.raydirx;
	ray_dir_y = d->p.raydiry;
	if (side == 1)
	{
		if (ray_dir_y < 0)
			d->p.wall_dir = 3;
		else
			d->p.wall_dir = 4;
	}
	else
	{
		if (ray_dir_x < 0)
			d->p.wall_dir = 1;
		else
			d->p.wall_dir = 2;
	}
}

int	rgbtoint(char *c)
{
	char	**colors;
	int		red;
	int		green;
	int		blue;

	colors = ft_split(c, ',');
	if (!colors[0] || !colors[1] || !colors[2])
	{
		ft_printf("Error: Invalid color range\n");
		exit(EXIT_FAILURE);
	}
	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	free_tab(colors);
	if (red < 0 || red > 255 || green < 0 || green > 255 \
	|| blue < 0 || blue > 255)
	{
		ft_printf("Error: Invalid color range\n");
		exit(EXIT_FAILURE);
	}
	return ((red << 16) | (green << 8) | blue);
}

void	render_ceilling_floor(t_data *d)
{
    int				x;
    int				y;
    unsigned int	cc;
    unsigned int	fc;

    x = 0;
    cc = rgbtoint(d->map.c_color);
    fc = rgbtoint(d->map.f_color);
    while (x++ < WIDTH)
    {
        y = 0;
        while (y++ <= HEIGHT / 2)
            put_pxl_to_img(d, x, y, cc);
        while (y < HEIGHT)
        {
            put_pxl_to_img(d, x, y, fc);
            y++;
        }
    }
    mlx_put_image_to_window(d->mlx, d->mlx_win,
        d->img, 0, 0);
}

void	ft_raycasting(t_data *d)
{
	int	x;
	// int	color;

	x = 0;
	render_ceilling_floor(d);
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
