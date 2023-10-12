/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:54:15 by pvong             #+#    #+#             */
/*   Updated: 2023/10/12 11:33:26 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map map)
{
	if (map.m_no)
		free(map.m_no);
	if (map.m_so)
		free(map.m_so);
	if (map.m_we)
		free(map.m_we);
	if (map.m_ea)
		free(map.m_ea);
	if (map.f_color)
		free(map.f_color);
	if (map.c_color)
		free(map.c_color);
	if (map.tab)
		free_tab(map.tab);
	if (map.tmp)
		free_tab(map.tmp);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	free_texture(t_data *data, t_texture *tex)
{
	if (!tex)
		return ;
	if (tex->file)
		free(tex->file);
	if (tex->i)
	{
		if (tex->i->img)
			mlx_destroy_image(data->mlx, tex->i->img);
		free(tex->i);
	}
	free(tex);
}

void	free_all_textures(t_data *data)
{
	int	i;

	i = 0;
	if (data->t_north)
		free_texture(data, data->t_north);
	if (data->t_south)
		free_texture(data, data->t_south);
	if (data->t_east)
		free_texture(data, data->t_east);
	if (data->t_west)
		free_texture(data, data->t_west);
	while (i < TEXTURE_NB)
	{
		if (data->tex[i])
			free(data->tex[i]);
		i++;
	}
}
