/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/09/29 18:05:31 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// D/M/Y : 29/09/2023
// Started working on rendering the texture
// Need to parse it and change the structures

void	ft_init_data(t_data *data)
{
	data->p.movespeed = 0.2;
	data->p.rotspeed = 0.05;
	data->p.forward = 0;
	data->p.backward = 0;
	data->p.left = 0;
	data->p.right = 0;
	data->p.rotate_left = 0;
	data->p.rotate_right = 0;
}

void	ft_load_img(t_data *data, t_img *img, char *file)
{
	img->height = 0;
	img->width = 0;
	img->img = mlx_xpm_file_to_image(data->mlx, file, &img->width, &img->height);
	if (!img->img)
	{
		ft_printf("Error: ft_load_img: %s\n", file);
		exit(EXIT_FAILURE);
	}
}

int	ft_get_img_pixel_color(t_img *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->ll) \
		+ (x * img->bpp / 8))));
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

t_texture	*ft_get_texture_img(t_data *data, char *file)
{
	t_texture	*tex;

	tex = ft_calloc(1, sizeof(t_texture));
	tex->i = ft_calloc(1, sizeof(t_img));
	ft_load_img(data, tex->i, file);
	data->tex[0] = ft_get_texture_addr(tex->i);
	return (tex);
}

void	ft_apply_texture(t_data *data, t_player *p, int x, int id)
{
	double		wall_x;
	double		t_x;
	double		t_y;
	int			y;
	int			color;
	t_texture	*tex;

	(void) id;
	wall_x = 0.0;
	// To change later on
	// tex = ft_get_texture_img(data, "./textures/pics_xpm/bluestone.xpm");
	tex = data->t_north;
	// 
	wall_x = ft_get_wall_x(data->p);
	t_x = (int)(wall_x * (double)tex->i->width);
	t_x = tex->i->width - t_x - 1;
	tex->step = 1.0 * tex->i->width / p->lineheight;
	tex->pos = (p->drawstart - HEIGHT / 2 + p->lineheight) * tex->step;
	y = p->drawstart;
	while (y++ < p->drawend)
	{
		t_y = ((int) tex->pos & ((tex->i->height / 2) - 1));
		tex->pos += tex->step;
		if (x >= 0 && y >= 0 && t_x >= 0 && t_y >= 0)
		{
			color = ft_get_img_pixel_color(tex->i, t_x, t_y);
			put_pxl_to_img(data, x, y, color);
		}
	}
}

int	main(void)
{
	t_data	data;

	ft_init_mlx(&data);
	ft_init_data(&data);
	// Temporary
	data.tex = ft_calloc(TEXTURE_NB, sizeof(int *));
	data.t_north = ft_calloc(1, sizeof(t_texture));
	data.t_north = ft_get_texture_img(&data, "./textures/pics_xpm/bluestone.xpm");
	// 
	// map_parsing(&data.map, "./map/first_map.cub");
	map_parsing(&data.map, "./map/test.cub");
	print_map(&data.map);
	ft_get_player_pos(&data, data.map.tab, data.map.tab_len + 2);
	ft_printf("player_pos: (%d, %d)\n", (int) data.p.posx, (int) data.p.posy);
	ft_printf("player direction: dirx: %d || diry: %d\n", (int) data.p.dirx, (int) data.p.diry);
	// free_map(data.map);

	ft_hook(&data);
}
