/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/09/21 14:47:17 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move(int keycode, t_data *data);

void	put_pxl_to_img(t_data *data, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4, \
			&color, sizeof(int));
	}
}

void	ft_init_mlx(t_data *data)
{
	data->relative_path = "./test.xpm";
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Hello world!");
	// data->img = mlx_xpm_file_to_image(data->mlx, data->relative_path, &data->img_width, &data->img_height);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->endian);
}

void	ft_hook(t_data *data)
{
	mlx_hook(data->mlx_win, DESTROY_NOTIFY, 0, ft_close, data);
	mlx_hook(data->mlx_win, KEY_PRESS, 0, ft_move, data);
	mlx_key_hook(data->mlx_win, ft_control_key, data);
	mlx_loop(data->mlx);
}

void	ft_draw_sq(t_data *data, int x, int y, int size, int color)
{
	int	start_x;
	int	start_y;

	start_x = x;
	start_y = y;
	while (start_x < x + size)
	{
		start_y = y;
		while (start_y < y + size)
		{
			put_pxl_to_img(data, start_x, start_y, color);
			start_y++;
		}
		start_x++;
	}
}


#define mapWidth 24
#define mapHeight 24

void	put_pxl_to_img2(t_data *data, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4, \
			&color, sizeof(int));
	}
}

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	ft_expose_hook(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->endian);
	return (0);
}

int	verLine(t_data *data, int x, int y1, int y2, int color)
{
	int	y;

	if (y2 < y1)
		y1 += y2; y2 = y1 - y2; y1 -= y2;
	if (y2 < 0 || y1 >= HEIGHT  || x < 0 || x >= WIDTH)
		return (0);
	if (y1 < 0)
		y1 = 0;
	if (y2 >= WIDTH)
		y2 = HEIGHT - 1;

	y = y1;
	while (y <= y2)
	{
		if (x > 0 && x <= WIDTH)
			put_pxl_to_img2(data, x, y, color);
		y++;
	}
	return (1);
}

int	ft_move(int keycode, t_data *data)
{
	int		action;
	double	oldplanex;

	action = 0;
	if (keycode == K_W)
	{
		action++;
		if (worldMap[(int) (data->p.posx + data->p.dirx * data->p.movespeed)]\
		[(int) data->p.posy] == 0)
			data->p.posx += data->p.dirx * data->p.movespeed;
		if (worldMap[(int) data->p.posx]\
		[(int) (data->p.posy + data->p.diry * data->p.movespeed)] == 0)
			data->p.posy += data->p.diry * data->p.movespeed;
	}
	if (keycode == K_A)
	{
		action++;
		if (worldMap[(int) (data->p.posx - data->p.planex * data->p.movespeed)][(int)data->p.posy] == 0)
			data->p.posx -= data->p.planex * data->p.movespeed;
		if (worldMap[(int) data->p.posx][(int)(data->p.posy - data->p.planey * data->p.movespeed)] == 0)
			data->p.posy -= data->p.planey * data->p.movespeed;
	}
	if (keycode == K_D)
	{
		action++;
		if (worldMap[(int) (data->p.posx + data->p.planex * data->p.movespeed)][(int)data->p.posy] == 0)
			data->p.posx += data->p.planex * data->p.movespeed;
		if (worldMap[(int) data->p.posx][(int)(data->p.posy + data->p.planey * data->p.movespeed)] == 0)
			data->p.posy += data->p.planey * data->p.movespeed;
	}
	if (keycode == K_AR_L)
	{
		action++;
		data->p.old_dirx = data->p.dirx;
		data->p.dirx = data->p.dirx * cos(data->p.rotspeed) - data->p.diry * sin(data->p.rotspeed);
		data->p.diry = data->p.old_dirx * sin(data->p.rotspeed) + data->p.diry * cos(data->p.rotspeed);
		oldplanex = data->p.planex;
		data->p.planex = data->p.planex * cos(data->p.rotspeed) - data->p.planey * sin(data->p.rotspeed);
		data->p.planey = oldplanex * sin(data->p.rotspeed) + data->p.planey * cos(data->p.rotspeed);
	}
	if (keycode == K_S)
	{
		action++;
		if (worldMap[(int) (data->p.posx - data->p.dirx * data->p.movespeed)]\
		[(int) data->p.posy] == 0)
			data->p.posx -= data->p.dirx * data->p.movespeed;
		if (worldMap[(int) data->p.posx]\
		[(int) (data->p.posy - data->p.diry * data->p.movespeed)] == 0)
			data->p.posy -= data->p.diry * data->p.movespeed;
	}
	if (keycode == K_AR_R)
	{
		action++;
		data->p.old_dirx = data->p.dirx;
		data->p.dirx = data->p.dirx * cos(-data->p.rotspeed) - data->p.diry * sin(-data->p.rotspeed);
		data->p.diry = data->p.old_dirx * sin(-data->p.rotspeed) + data->p.diry * cos(-data->p.rotspeed);
		oldplanex = data->p.planex;
		data->p.planex = data->p.planex * cos(-data->p.rotspeed) - data->p.planey * sin(-data->p.rotspeed);
		data->p.planey = oldplanex * sin(-data->p.rotspeed) + data->p.planey * cos(-data->p.rotspeed);
	}
	if (action > 0)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_expose_hook(data);
		ft_raycasting(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img , 0, 0);
	}
	return (0);
}

void	ft_raycasting(t_data *d)
{
	int	h = HEIGHT;
	int	w = WIDTH;
	int	x;

	x = 0;
	while (x < w)
	{
		d->p.camerax = 2 * x / (double) w - 1;
		d->p.raydirx = d->p.dirx + d->p.planex * d->p.camerax;
		d->p.raydiry = d->p.diry + d->p.planey * d->p.camerax;

		d->p.mapx = (int) d->p.posx;
		d->p.mapy = (int) d->p.posy;

		d->p.deltadistx = (d->p.raydirx == 0) ? 1e30 : fabs(1 / d->p.raydirx);
		d->p.deltadisty = (d->p.raydiry == 0) ? 1e30 : fabs(1 / d->p.raydiry);

		d->p.hit = 0;
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
			if (worldMap[d->p.mapx][d->p.mapy] > 0)
				d->p.hit = 1;
		}
		if (d->p.side == 0)
			d->p.perpwalldist = (d->p.sidedistx - d->p.deltadistx);
		else
			d->p.perpwalldist = (d->p.sidedisty - d->p.deltadisty);
		d->p.lineheight = (int) (h / d->p.perpwalldist);
		
		d->p.drawstart = -(d->p.lineheight) / 2 + h / 2;
		if (d->p.drawstart < 0)
			d->p.drawstart = 0;
		d->p.drawend = d->p.lineheight / 2 + h / 2;
		if (d->p.drawend >= h) d->p.drawend = h - 1;
		int color;
		switch(worldMap[d->p.mapx][d->p.mapy])
		{
			case 1:  color = 0xFF0000;  break; //red
			case 2:  color = 0x00FF00;  break; //green
			case 3:  color = 0x0000FF;   break; //blue
			case 4:  color = 0xFFFFFF;  break; //white
			default: color = 0xFFFF00; break; //yellow
		}
		if (d->p.side == 1)
			color = color / 2;
		verLine(d, x, d->p.drawstart, d->p.drawend, color);
		x++;
	}
}

int	main(void)
{
	t_data	data;

	ft_init_mlx(&data);
	// map_parsing(&data.map, "./map/first_map.cub");
	// print_map(&data.map);
	// free_map(data.map);
	ft_raycasting(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	
	// HOOKS
	data.p.movespeed = 5.0 / 10;
	data.p.rotspeed = 3.0 / 50;
	ft_hook(&data);
}