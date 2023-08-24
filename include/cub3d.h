/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:51:14 by pvong             #+#    #+#             */
/*   Updated: 2023/08/24 14:41:31 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "x11events.h"
# if OS == APPLE
#  include "../mlx/mlx.h"
#  include "key_macos.h"
# else
#  include "../mlx_linux/mlx.h"
# endif

/* -------------------------------------------------------------------------- */
/*                                   STRUCT                                   */
/* -------------------------------------------------------------------------- */

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_map
{
	int		size;
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
void		free_map(t_map map);


#endif