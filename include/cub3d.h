/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:51:14 by pvong             #+#    #+#             */
/*   Updated: 2023/09/12 22:38:55 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# if __linux__
#  define _GNU_SOURCE
# endif
# include "libft.h"
# include "x11events.h"
# include "mlx.h"
# include "keycodes.h"
# include <math.h>

/* -------------------------------------------------------------------------- */
/*                                   DEFINE                                   */
/* -------------------------------------------------------------------------- */

# define WIDTH	1920
# define HEIGHT 1080

/* -------------------------------------------------------------------------- */
/*                                   STRUCT                                   */
/* -------------------------------------------------------------------------- */

typedef struct s_map
{
	int		tab_len;
	int		start;
	int		line;
	char	*m_no;
	char	*m_so;
	char	*m_we;
	char	*m_ea;
	char	*f_color;
	char	*c_color;
	char	**tab;
}	t_map;

typedef struct s_data
{
	int		x;
	int		y;

	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img_ptr;
	void	*img2;
	void	*img_ptr2;
	int		bpp;
	int		ll;
	int		endian;
	char	*relative_path;
	int		img_width;
	int		img_height;
	t_map	map;
}	t_data;

typedef struct s_coord
{
	int	s_x;
	int	s_y;
	int	e_x;
	int	e_y;
	int	color;
}	t_coord;

/* -------------------------------------------------------------------------- */
/*                                    HOOK                                    */
/* -------------------------------------------------------------------------- */

void		ft_hook(t_data *data);
int			ft_control_key(int keycode, t_data *data);

/* -------------------------------------------------------------------------- */
/*                                 MAP_PARSING                                */
/* -------------------------------------------------------------------------- */

int			map_parsing2(t_map *map, char *map_file);
int			map_parsing(t_map *map, char *map_file);

/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */

/* utils.c */

char		*ft_strtrim2(char *s1, char *set);
int			ft_close(void);
void		print_map(t_map *map);

/* free */
void		free_map(t_map map);
void		free_tab(char **tab);

#endif