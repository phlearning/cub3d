/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/09/12 22:39:25 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pxl_to_img(t_data *data, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4, \
			&color, sizeof(int));
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_ptr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_init_mlx(t_data *data)
{
	data->relative_path = "./test.xpm";
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Hello world!");
	// data->img = mlx_xpm_file_to_image(data->mlx, data->relative_path, &data->img_width, &data->img_height);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->endian);

}

int draw_mouse_coordinates(int mousecode, int x, int y, t_data *data)
{
    char *coordinates_str = NULL;

	if (mousecode == M_CLK_L)
	{
		// FONCTION INTERDITE ATTENTION asprintf
    	asprintf(&coordinates_str, "Mouse Coordinates: (%d, %d)", x, y);
		// FONCTION INTERDITE ATTENTION asprintf
    	mlx_clear_window(data->mlx, data->mlx_win);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
    	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0xFFFFFF, coordinates_str);
		free(coordinates_str);
	}
	return (0);
}

void	ft_hook(t_data *data)
{
	mlx_hook(data->mlx_win, DESTROY_NOTIFY, 0, ft_close, data);
	mlx_key_hook(data->mlx_win, ft_control_key, data);
	// mlx_mouse_hook(data->mlx_win, draw_mouse_coordinates, data);
	mlx_loop(data->mlx);
}

void	ft_draw_sq(t_data *data, t_coord xy)
{
	// int	x;
	int	y;

	// x = xy.s_x;
	y = xy.s_y;
	while (xy.s_x < xy.e_x)
	{
		xy.s_y = y;
		while (xy.s_y < xy.e_y)
		{
			put_pxl_to_img(data, xy.s_x, xy.s_y, xy.color);
			xy.s_y++;
		}
		xy.s_x++;
	}
}

// int	main(void)
// {
// 	t_data	data;
// 	// t_coord	xy;
// 	// t_coord	xy2;

// 	ft_init_mlx(&data);
// 	map_parsing(&data.map, "./map/first_map.cub");
// 	print_map(&data.map);
// 	free_map(data.map);
// 	// xy.s_x = 500; xy.s_y = 500; xy.e_x = 700; xy.e_y = 700; xy.color = 0x0000FF;
// 	// ft_draw_sq(&data, xy);
// 	// xy2.s_x = 250; xy2.s_y = 250; xy2.e_x = 300; xy2.e_y = 300; xy2.color = 0xFF0000;
// 	// ft_draw_sq(&data, xy2);
// 	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	// ft_hook(&data);
// 	return (0);
// }

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

void	put_pxl_to_img2(t_data *data, int x, int y, int color)
{
	if (x < screenWidth && y < screenHeight)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * screenWidth * y + x * 4, \
			&color, sizeof(int));
	}
}

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	verLine(t_data *data, int x, int y1, int y2, int color)
{
	if(y2 < y1) {y1 += y2; y2 = y1 - y2; y1 -= y2;} //swap y1 and y2
	if(y2 < 0 || y1 >= screenHeight  || x < 0 || x >= screenWidth) return 0; //no single point of the line is on screen
	if(y1 < 0) y1 = 0; //clip
	if(y2 >= screenWidth) y2 = screenHeight - 1; //clip

	for (int y = y1; y <= y2; y++)
	{
		if (x > 0 && x <= screenWidth)
			put_pxl_to_img2(data, x, y, color);
	}
	return (1);
}

int	main(void)
{
	t_data	data;
	double	posX = 22;
	double	posY = 12;
	double	dirX = -1;
	double	dirY = 0;
	double	planeX = 0;
	double	planeY = 0.66;
	int	h = screenHeight;
	int	w = screenWidth;

	// INIT
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, screenWidth, screenHeight, "Hello world!");
	data.img = mlx_new_image(data.mlx, screenWidth, screenHeight);
	data.img_ptr = mlx_get_data_addr(data.img, &data.bpp, &data.ll, &data.endian);
	
	for(int x = 0; x < w; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double) w - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;

	  //which box of the map we're in
      int mapX = (int) posX;
      int mapY = (int) posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

	   //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
	   //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      } 
	        //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);
	       //Calculate height of line to draw on screen
      int lineHeight = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2;
      if(drawEnd >= h)drawEnd = h - 1;
	        //choose wall color
      int color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = 0xFF0000;  break; //red
        case 2:  color = 0x00FF00;  break; //green
        case 3:  color = 0x0000FF;   break; //blue
        case 4:  color = 0xFFFFFF;  break; //white
        default: color = 0xFFFF00; break; //yellow
      }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      verLine(&data, x, drawStart, drawEnd, color);
	//   ft_printf("x: %d, drawStart: %d, drawEnd: %d\n", x, drawStart, drawEnd);
    }
	
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	// HOOKS
	ft_hook(&data);
}