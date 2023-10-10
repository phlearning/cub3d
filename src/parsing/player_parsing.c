/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:45:46 by pvong             #+#    #+#             */
/*   Updated: 2023/10/10 11:35:18 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player_ns(t_data *d, int is_north)
{
	if (is_north)
	{
		d->p.dirx = 0;
		d->p.diry = -1;
		d->p.planex = 0.66;
		d->p.planey = 0;
	}
	else
	{
		d->p.dirx = 0;
		d->p.diry = 1;
		d->p.planex = -0.66;
		d->p.planey = 0;
	}
}

void	ft_player_we(t_data *d, int is_west)
{
	if (is_west)
	{
		d->p.dirx = -1;
		d->p.diry = 0;
		d->p.planex = 0;
		d->p.planey = -0.66;
	}
	else
	{
		d->p.dirx = 1;
		d->p.diry = 0;
		d->p.planex = 0;
		d->p.planey = 0.66;
	}
}

void	ft_get_player_direction(t_data *d, char c)
{
	if (c == 'N')
		ft_player_ns(d, TRUE);
	if (c == 'S')
		ft_player_ns(d, FALSE);
	if (c == 'W')
		ft_player_we(d, TRUE);
	if (c == 'E')
		ft_player_we(d, FALSE);
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
void	ft_get_player_pos(t_data *data, char **tab, int tab_len)
{
	int	x;
	int	y;
	int	line_len;
	int	found;

	y = -1;
	found = 0;
	line_len = ft_strlen(tab[0]);
	while (++y < tab_len)
	{
		x = -1;
		while (++x < line_len)
		{
			if (ft_contain_player_char(data, tab[y][x]))
			{
				data->p.posx = (double) x + 0.5;
				data->p.posy = (double) y + 0.5;
				found++;
			}
		}
	}
	if (found == 1)
		return ;
	else
		error_exit2("Reason: player position in map", 1);
}
