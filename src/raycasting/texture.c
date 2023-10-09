/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:48:50 by pvong             #+#    #+#             */
/*   Updated: 2023/10/09 16:16:31 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*ft_get_tex(t_data *data, int id)
{
	if (id == 1)
		return (data->t_north);
	else if (id == 2)
		return (data->t_south);
	else if (id == 3)
		return (data->t_west);
	else if (id == 4)
		return (data->t_east);
	return (NULL);
}

t_texture	*ft_get_texture_img(t_data *data, char *file, int n)
{
	t_texture	*tex;

	tex = ft_calloc(1, sizeof(t_texture));
	tex->i = ft_calloc(1, sizeof(t_img));
	ft_load_img(data, tex->i, file);
	data->tex[n] = ft_get_texture_addr(tex->i);
	return (tex);
}

int	*ft_get_texture_addr(t_img *i)
{
	int	*tmp;
	int	row_start;
	int	y;

	tmp = ft_calloc(i->height * i->width, sizeof(int));
	if (!tmp)
		return (NULL);
	i->addr = mlx_get_data_addr(i->img, &(i->bpp), &(i->ll), &(i->endian));
	y = 0;
	while (y < i->height)
	{
		row_start = y * i->width;
		ft_memcpy(tmp + row_start, i->addr + row_start, i->width * sizeof(int));
		y++;
	}
	return (tmp);
}

void	ft_apply_texture(t_data *data, t_player *p, int x, int id)
{
	double		wall_x;
	int			y;
	int			color;
	t_texture	*tex;

	wall_x = 0.0;
	tex = ft_get_tex(data, id);
	wall_x = ft_get_wall_x(data->p);
	tex->t_x = (int)(wall_x * (double)tex->i->width);
	tex->t_x = tex->i->width - tex->t_x - 1;
	tex->step = 1.0 * tex->i->width / p->lineheight;
	tex->pos = (p->drawstart - HEIGHT / 2 + p->lineheight / 2) * tex->step;
	y = p->drawstart;
	while (y++ < p->drawend)
	{
		tex->t_y = ((int) tex->pos & ((tex->i->height) - 1));
		tex->pos += tex->step;
		if (x >= 0 && y >= 0 && tex->t_x >= 0 && tex->t_y >= 0)
		{
			color = ft_get_img_pixel_color(tex->i, tex->t_x, tex->t_y);
			ft_pxl_to_img(data, x, y, color);
		}
	}
}
