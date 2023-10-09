/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/10/09 17:19:09 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_test_open_text(t_data *data)
{
	ft_test_open(data->map.m_no);
	ft_test_open(data->map.m_ea);
	ft_test_open(data->map.m_we);
	ft_test_open(data->map.m_so);
}

int	ft_init(t_data *data, int ac, char **av)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	ft_init_data(data);
	if (ac == 2)
	{
		ft_check_extension(av, ft_strlen(av[1]));
		map_parsing(data, &data->map, av[1]);
	}
	else
		error_exit2("Error: Usage: ./cub3D [map.cub]", 0);
	ft_test_open_text(data);
	data->int_f_color = ft_rgbtoint(data->map.f_color);
	data->int_c_color = ft_rgbtoint(data->map.c_color);
	ft_init_mlx(data);
	if (!data->mlx)
		error_exit2("Error: mlx unitialized", 1);
	data->tex = ft_calloc(TEXTURE_NB, sizeof(int *));
	data->t_north = ft_get_texture_img(data, data->map.m_no, 0);
	data->t_south = ft_get_texture_img(data, data->map.m_so, 1);
	data->t_east = ft_get_texture_img(data, data->map.m_ea, 2);
	data->t_west = ft_get_texture_img(data, data->map.m_we, 3);
	ft_get_player_pos(data, data->map.tab, data->map.tab_len + 2);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
		ft_init(&data, ac, av);
	else
		error_exit2("Error: Usage: ./cub3D [map.cub]", 0);
	ft_hook(&data);
	ft_close(&data);
}
