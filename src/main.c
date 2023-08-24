/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/08/24 16:30:42 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_data *data)
{
	data->relative_path = "./test.xpm";
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "Hello world!");
	data->img = mlx_xpm_file_to_image(data->mlx, data->relative_path, &data->img_width, &data->img_height);
}

void	ft_hook(t_data *data)
{
	mlx_hook(data->mlx_win, DESTROY_NOTIFY, 0, ft_close, data);
	mlx_key_hook(data->mlx_win, ft_control_key, data);
	mlx_loop(data->mlx);
}

int	main(void)
{
	t_data	data;

	// ft_init_mlx(&data);
	map_parsing(&data.map, "./map/first_map.cub");
	// mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	print_map(&data.map);
	// ft_hook(&data);
	free_map(data.map);
	return (0);
}

// int main(void)
// {
// 	t_map	map;

// 	map_parsing(&map, "./map/first_map.cub");
// 	print_map(&map);
// 	free_map(map);
// }