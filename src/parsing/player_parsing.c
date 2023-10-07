/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:45:46 by pvong             #+#    #+#             */
/*   Updated: 2023/10/07 21:41:02 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Update the direction and the plane once either
 * N, S, E or W is found in the map.
 * 
 * (dirx , diry) || (planex, planey):
 * 	(-1, 0) || (0, 0.66) - North
 * 	(1, 0) || (0, -0.66) - South
 * 	(0, -1) || (0.66, 0) - West
 * 	(0, 1) || (-0.66, 0) - East
 */
void	ft_get_player_direction(t_data *d, char c)
{
	if (c == 'N')
	{
		d->p.dirx = 0;
		d->p.diry = -1;
		d->p.planex = 0.66;
		d->p.planey = 0;
	}
	if (c == 'S')
	{
		d->p.dirx = 0;
		d->p.diry = 1;
		d->p.planex = -0.66;
		d->p.planey = 0;
	}
	if (c == 'E')
	{
		d->p.dirx = 1;
		d->p.diry = 0;
		d->p.planex = 0;
		d->p.planey = 0.66;
	}
	if (c == 'W')
	{
		d->p.dirx = -1;
		d->p.diry = 0;
		d->p.planex = 0;
		d->p.planey = -0.66;
	}
}

/**
 * Compare the char in the map with either N, S, E or W
 * @param data 
 * @param c 
 * @return int 
 */
int	ft_contain_player_char(t_data *data, char c)
{
	char	char_player[4];
	int		i;

	char_player[0] = 'N';
	char_player[1] = 'S';
	char_player[2] = 'E';
	char_player[3] = 'W';
	i = -1;
	(void) data;
	while (++i < 4)
	{
		if (c == char_player[i])
		{
			ft_get_player_direction(data, c);
			return (1);
		}
	}
	return (0);
}

/**
 * Look for the player position in the map, then update
 * the posx and posy in the data struct
 * @param data
 * @param tab 
 * @param tab_len 
 * @return int 
 */
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
			if (ft_contain_player_char(data, tab[y][x]))
			{
				data->p.posx = (double) x + 0.5;
				data->p.posy = (double) y + 0.5;
				found++;
			}
			x++;
		}
		y++;
	}
	if (found == 1)
		return (1);
	else
	{
		// ft_printf("Error player position in map\n");
		error_exit2("Error: player position in map", 1);
	}
	return (0);
}
