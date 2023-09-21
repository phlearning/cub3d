/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:36:20 by pvong             #+#    #+#             */
/*   Updated: 2023/09/21 15:49:52 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pxl_to_img(t_data *data, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4, \
			&color, sizeof(int));
	}
}

/**
 * Draw a vertical line going from y1 to y2 on x
 * @param t_data *data, the struct containing the mlx info
 * @param int x 
 * @param int y1
 * @param int y2
 * @param int color 
 * @return int 0 or 1, 0 if the coords are out of the screen and 1 if ok
 */
int	ft_drawline(t_data *data, int x, int y1, int y2, int color)
{
	int	y;

	if (y2 < y1)
	{
		y1 += y2;
		y2 = y1 - y2;
		y1 -= y2;
	}
	if (y2 < 0 || y1 >= HEIGHT || x < 0 || x >= WIDTH)
		return (0);
	if (y1 < 0)
		y1 = 0;
	if (y2 >= WIDTH)
		y2 = HEIGHT - 1;

	y = y1;
	while (y <= y2)
	{
		if (x > 0 && x <= WIDTH)
			put_pxl_to_img(data, x, y, color);
		y++;
	}
	return (1);
}

/**
 * Draw a square
 * @param t_data *data, the struct containing mlx info 
 * @param int x 
 * @param int y 
 * @param int size 
 * @param int color
 */
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