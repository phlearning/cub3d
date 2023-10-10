/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:36:20 by pvong             #+#    #+#             */
/*   Updated: 2023/10/10 11:40:31 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pxl_to_img(t_data *data, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->addr + 4 * WIDTH * y + x * 4, \
			&color, sizeof(int));
	}
}

void	ft_load_img(t_data *data, t_img *img, char *file)
{
	img->height = 0;
	img->width = 0;
	img->img = mlx_xpm_file_to_image(data->mlx, \
		file, &img->width, &img->height);
	if (!img->img)
	{
		ft_printf("Error\n");
		ft_printf("Reason: ft_load_img: %s\n", file);
		exit(EXIT_FAILURE);
	}
}

int	ft_get_img_pixel_color(t_img *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->ll) \
		+ (x * img->bpp / 8))));
}
