/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:14:24 by pvong             #+#    #+#             */
/*   Updated: 2023/10/09 17:24:36 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_char_exit(char *s, char c, int exit_n)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			n++;
		i++;
	}
	if (n > exit_n)
		error_exit2("Error: Invalid color range", 1);
	return (0);
}

int	ft_rgbtoint(char *c)
{
	char	**colors;
	int		red;
	int		green;
	int		blue;

	ft_count_char_exit(c, ',', 2);
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
			d->p.wall_dir = 1;
		else
			d->p.wall_dir = 2;
	}
	else
	{
		if (ray_dir_x < 0)
			d->p.wall_dir = 3;
		else
			d->p.wall_dir = 4;
	}
}

void	ft_render_ceilling_floor(t_data *d)
{
	int				x;
	int				y;
	unsigned int	cc;
	unsigned int	fc;

	x = 0;
	cc = d->int_c_color;
	fc = d->int_f_color;
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ <= HEIGHT / 2)
			ft_pxl_to_img(d, x, y, cc);
		while (y < HEIGHT)
		{
			ft_pxl_to_img(d, x, y, fc);
			y++;
		}
	}
	mlx_put_image_to_window(d->mlx, d->mlx_win,
		d->img, 0, 0);
}
