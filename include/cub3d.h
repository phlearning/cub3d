/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:51:14 by pvong             #+#    #+#             */
/*   Updated: 2023/10/06 15:41:03 by pvong            ###   ########.fr       */
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
# define INCREMENT 10
# define TILE_SET "0NEWS"
# define TILE_N_WALLS "10NEWS-"
# define TILE_N_WALL "10NEWS"
# define SIZE_XPM 64
# define TEXTURE_NB 4
# define TRUE 1
# define FALSE 0

/* Error message */

# define ERR_NORTH_TEX "Error: North's texture is invalid"
# define ERR_EAST_TEX "Error: East's texture is invalid"
# define ERR_WEST_TEX "Error: West's texture is invalid"
# define ERR_SOUTH_TEX "Error: South's texture is invalid"
# define ERR_F_COLOR "Error: Floor's color is invalid"
# define ERR_C_COLOR "Error: Ceiling's color is invalid"

/* tmp color */
# define RGB_RED 0xff0000
# define RGB_GREEN 0x00ff00
# define RGB_BLUE 0x0000ff
# define RGB_MAGENTA 0xff00ff
# define RGB_BROWN 0xa52a2a

/* -------------------------------------------------------------------------- */
/*                                   STRUCT                                   */
/* -------------------------------------------------------------------------- */

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	char	*file;
	float	step;
	float	pos;
	t_img	*i;
}	t_texture;

typedef struct s_map
{
	int		tab_len;
	int		max_line_len;
	int		start;
	int		line;
	int		error;
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
	int		mapx;
	int		mapy;
	// Variables concernant les rayons
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	// -----
	int		wall_dir;
	// Draw vertical line
	int		lineheight;
	int		drawstart;
	int		drawend;
	// ----
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
}	t_player;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	int			x;
	int			y;

	void		*mlx;
	void		*mlx_win;
	void		*img;
	void		*addr;
	int			bpp;
	int			ll;
	int			endian;
	int			img_width;
	int			img_height;
	t_player	p;
	t_map		map;
	t_texture	*t_north;
	t_texture	*t_south;
	t_texture	*t_east;
	t_texture	*t_west;
	char		*f_color;
	char		*c_color;
	int			**tex;
}	t_data;

/* -------------------------------------------------------------------------- */
/*                                 RAYCASTING                                 */
/* -------------------------------------------------------------------------- */

/* raycasting.c */

void		ft_advance_ray_step(t_data *d);
void		ft_calc_drawing_range(t_data *d);
void	    render_ceilling_floor(t_data *d);
void		ft_raycasting(t_data *d);
void		ft_get_wall_dir(t_data *d);

/* raycasting2.c */

void		ft_calc_sidedist(t_data *d);
int			ft_get_color(int side, double ray_dir_y, double ray_dir_x);
double		ft_get_wall_x(t_player p);
void		ft_init_ray(t_data *d, int x);

/* texture.c */

t_texture	*ft_get_tex(t_data *data, int id);
t_texture	*ft_get_texture_img(t_data *data, char *file, int n);
int			*ft_get_texture_addr(t_img *i);
void		ft_apply_texture(t_data *data, t_player *p, int x, int id);

/* -------------------------------------------------------------------------- */
/*                                    HOOK                                    */
/* -------------------------------------------------------------------------- */

/* events.c */

void		ft_move_up_down(t_data *d, int dir, char **map);
void		ft_move_left_right(t_data *d, int dir, char **map);
void		ft_rotate_left_right(t_data *d, int dir);
int			ft_move(int keycode, t_data *data);

/* hooks.c */

int			ft_expose_hook(t_data *data);
void		ft_hook(t_data *data);
int			ft_loop(t_data *data);
int			ft_read_movement(t_data *d);
void		ft_update_img(t_data *data);

/* key_hook.c */

void		ft_key_hook(t_data *data);
int			ft_key_press(int keycode, t_data *data);
int			ft_key_release(int keycode, t_data *data);
int			ft_move_press(int k, t_data *d);
int			ft_move_release(int k, t_data *d);

/* -------------------------------------------------------------------------- */
/*                                    INIT                                    */
/* -------------------------------------------------------------------------- */

void		ft_init_mlx(t_data *data);
void		ft_init_data(t_data *data);

/* -------------------------------------------------------------------------- */
/*                                   PARSING                                  */
/* -------------------------------------------------------------------------- */

// TEMPORAY TMP TEMP

int			ft_map_is_last(t_map *map);

/* map_parsing.c */

void		ft_change_char(char *s, char c1, char replace_by);
void		ft_fill(char *s, char c, int len);
int			ft_get_longest_tab_len(char **tab, int tab_len);
char		**ft_rework_tab(char **tab, int v_len, int h_len, char replace);
int			map_parsing(t_data *data, t_map *map, char *map_file);
int			map_parsing2(t_map *map, char *map_file);
int			ft_check_map_vertically(char **tab, char *c);
int			ft_check_map_horizontally(char **tab, char *c);

/* player_parsing.c */

void		ft_get_player_direction(t_data *d, char c);
int			ft_contain_player_char(t_data *data, char c);
int			ft_get_player_pos(t_data *data, char **tab, int tab_len);

/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */

/* utils.c */

void		print_tab(char **tab);
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
int			ft_draw_verline(t_data *data, t_pos *start_pos, \
				int length, int color);
int			ft_get_img_pixel_color(t_img *img, int x, int y);
void		ft_load_img(t_data *data, t_img *img, char *file);
void		put_pxl_to_img(t_data *data, int x, int y, int color);

/* free */
void		free_map(t_map map);
void		free_tab(char **tab);
void		free_texture(t_data *data, t_texture *tex);
void		free_all_textures(t_data *data);

#endif