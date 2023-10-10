/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:02:45 by pvong             #+#    #+#             */
/*   Updated: 2023/10/10 11:35:59 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *s, int n)
{
	ft_printf("Error\n");
	perror(s);
	exit(n);
}

void	error_exit2(char *s, int n)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	exit(n);
}

void	error_exit3(char *s, char *s2, int n)
{
	char	*str;

	str = ft_strjoin(s, s2);
	perror(str);
	free(str);
	exit(n);
}

/**
 * Works in conjunction with mlx_hook when closing the window, 
 * we exit the program. It needs to be an int for the mlx_hook.
 * @return int 
 */
int	ft_close(t_data *data)
{
	if (!data)
		exit(EXIT_FAILURE);
	free_all_textures(data);
	free_map(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	exit(EXIT_SUCCESS);
	return (0);
}
