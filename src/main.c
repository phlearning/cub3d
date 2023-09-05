/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/09/02 08:44:10 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pxl_to_img(t_data *data, int x, int y, int color)
{
	if (x < WIDTH && y < WIDTH)
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

int draw_mouse_coordinates(int mousecode, int x, int y, t_data *data)
{
    char *coordinates_str = NULL;

	if (mousecode == M_CLK_L)
	{
		// FONCTION INTERDITE ATTENTION asprintf
    	asprintf(&coordinates_str, "Mouse Coordinates: (%d, %d)", x, y);
		// FONCTION INTERDITE ATTENTION asprintf
    	mlx_clear_window(data->mlx, data->mlx_win);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
    	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0xFFFFFF, coordinates_str);
		free(coordinates_str);
	}
	return (0);
}

void	ft_hook(t_data *data)
{
	mlx_hook(data->mlx_win, DESTROY_NOTIFY, 0, ft_close, data);
	mlx_key_hook(data->mlx_win, ft_control_key, data);
	mlx_mouse_hook(data->mlx_win, draw_mouse_coordinates, data);
	mlx_loop(data->mlx);
}

void	ft_draw_sq(t_data *data, t_coord xy)
{
	// int	x;
	int	y;

	// x = xy.s_x;
	y = xy.s_y;
	while (xy.s_x < xy.e_x)
	{
		xy.s_y = y;
		while (xy.s_y < xy.e_y)
		{
			put_pxl_to_img(data, xy.s_x, xy.s_y, xy.color);
			xy.s_y++;
		}
		xy.s_x++;
	}
}

int	main(void)
{
	t_data	data;
	// t_coord	xy;
	// t_coord	xy2;

	ft_init_mlx(&data);
	map_parsing(&data.map, "./map/first_map.cub");
	print_map(&data.map);
	free_map(data.map);
	// xy.s_x = 500; xy.s_y = 500; xy.e_x = 700; xy.e_y = 700; xy.color = 0x0000FF;
	// ft_draw_sq(&data, xy);
	// xy2.s_x = 250; xy2.s_y = 250; xy2.e_x = 300; xy2.e_y = 300; xy2.color = 0xFF0000;
	// ft_draw_sq(&data, xy2);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	ft_hook(&data);
	return (0);
}
