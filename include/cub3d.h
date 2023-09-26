/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:51:14 by pvong             #+#    #+#             */
/*   Updated: 2023/09/26 15:27:44 by pvong            ###   ########.fr       */
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

# define WIDTH	1280
# define HEIGHT 960
# define INCREMENT 10
# define TILE_SET "0NSEW"
# define SIZE_XPM 64

/* tmp color */
# define RGB_RED 0xff0000
# define RGB_GREEN 0x00ff00
# define RGB_BLUE 0x0000ff
# define RGB_MAGENTA 0xff00ff
# define RGB_BROWN 0xa52a2a

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
	char	**tmp;
}	t_map;

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	old_dirx;
	double	diry;
	double	planex;
	double	planey;
	double	movespeed;
	double	rotspeed;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
}	t_player;

typedef struct s_data
{
	int			x;
	int			y;

	void		*mlx;
	void		*mlx_win;
	void		*img;
	void		*img_ptr;
	void		*img2;
	void		*img_ptr2;
	int			bpp;
	int			ll;
	int			endian;
	char		*relative_path;
	int			img_width;
	int			img_height;
	t_player	p;
	t_map		map;
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
/*                                 RAYCASTING                                 */
/* -------------------------------------------------------------------------- */

/* raycasting.c */

void		ft_advance_ray_step(t_data *d);
void		ft_calc_drawing_range(t_data *d);
void		ft_raycasting(t_data *d);

/* raycasting2.c */

int			ft_get_color(int side, double ray_dir_y, double ray_dir_x);
void		ft_init_ray(t_data *d, int x);
void		ft_calc_sidedist(t_data *d);

/* -------------------------------------------------------------------------- */
/*                                    HOOK                                    */
/* -------------------------------------------------------------------------- */

int			ft_control_key(int keycode, t_data *data);
int			ft_expose_hook(t_data *data);
void		ft_hook(t_data *data);
int			ft_move(int keycode, t_data *data);

/* -------------------------------------------------------------------------- */
/*                                    INIT                                    */
/* -------------------------------------------------------------------------- */

void		ft_init_mlx(t_data *data);

/* -------------------------------------------------------------------------- */
/*                                   PARSING                                  */
/* -------------------------------------------------------------------------- */

/* map_parsing.c */

void		ft_change_char(char *s, char c1, char replace_by);
void		ft_fill(char *s, char c, int len);
int			ft_get_longest_tab_len(char **tab, int tab_len);
char		**ft_rework_tab(char **tab, int v_len, int h_len, char replace);
int			map_parsing(t_map *map, char *map_file);
int			map_parsing2(t_map *map, char *map_file);

/* player_parsing.c */

void		ft_get_player_direction(t_data *d, char c);
int			ft_contain_player_char(t_data *data, char c);
int			ft_get_player_pos(t_data *data, char **tab, int tab_len);

/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */

/* utils.c */

char		*ft_strtrim2(char *s1, char *set);
int			ft_close(t_data *data);
void		error_exit(char *s, int n);
void		error_exit2(char *s, int n);
void		print_map(t_map *map);
int			ft_open(char *file);
int			ft_compare_set(int n, char *s);

/* utils_mlx.c */

void		ft_draw_sq(t_data *data, int x, int y, int size, int color);
int			ft_drawline(t_data *data, int x, int y1, int y2, int color);
void		put_pxl_to_img(t_data *data, int x, int y, int color);

/* free */
void		free_map(t_map map);
void		free_tab(char **tab);

#endif