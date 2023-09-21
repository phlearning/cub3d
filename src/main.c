/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/09/21 16:46:56 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move(int keycode, t_data *data);

#define mapWidth 24
#define mapHeight 24

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
		// ft_printf("x: %d || drawstart: %d || drawend: %d || color: %d\n", x, d->p.drawstart, d->p.drawend, color);
		ft_drawline(d, x, d->p.drawstart, d->p.drawend, color);
		x++;
	}
}

int	ft_contain_player_char(char c)
{
	char	char_player[4];
	int		i;

	char_player[0] = 'N';
	char_player[1] = 'S';
	char_player[2] = 'E';
	char_player[3] = 'W';
	i = -1;
	while (++i < 4)
	{
		if (c == char_player[i])
		{
			return (1);
		}
	}
	return (0);
}

int	ft_get_player_pos(t_data *data, char **tab, int tab_len)
{
	int	x;
	int	y;
	int	line_len;
	int	found;

	x = 0;
	y = 0;
	found = 0;
	line_len = ft_strlen(tab[0]);
	while (y < tab_len)
	{
		x = 0;
		while (x < line_len)
		{
			if (ft_contain_player_char(tab[y][x]))
			{
				data->p.posx = (double) x;
				data->p.posy = (double) y;
				found++;
			}
			x++;
		}
		y++;
	}
	if (found == 1)
		return (1);
	else
		ft_printf("Error player position in map\n");
	return (0);
}

int	main(void)
{
	t_data	data;

	data.p.posx = 12;
	data.p.posy = 12;
	data.p.dirx = -1;
	data.p.diry = 0;
	data.p.planex = 0;
	data.p.planey = 0.66;

	// ft_init_mlx(&data);
	map_parsing(&data.map, "./map/first_map.cub");
	print_map(&data.map);
	ft_get_player_pos(&data, data.map.tab, data.map.tab_len + 2);
	ft_printf("player_pos: (%d, %d)\n", (int) data.p.posx, (int) data.p.posy);
	free_map(data.map);
	// ft_raycasting(&data);
	// mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	
	// // HOOKS

	// data.p.movespeed = 5.0 / 10;
	// data.p.rotspeed = 3.0 / 50;
	// ft_hook(&data);
}