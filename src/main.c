/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:42:58 by pvong             #+#    #+#             */
/*   Updated: 2023/08/22 16:43:27 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img;
// 	char	*relative_path = "./test.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
// 	mlx_loop(mlx);
//	return (0);
// }

typedef	struct s_map
{
	char	*m_no;
	char	*m_so;
	char	*m_we;
	char	*m_ea;
	char	*f_color;
	char	*c_color;
	char	**tab;
	int		size;
}	t_map;

void	print_map(t_map map)
{
	int	i;
	ft_printf("=====\n");
	ft_printf("m_no: %s\n", map.m_no);
	ft_printf("m_so: %s\n", map.m_so);
	ft_printf("m_we: %s\n", map.m_we);
	ft_printf("m_ea: %s\n", map.m_ea);
	ft_printf("f_color: %s\n", map.f_color);
	ft_printf("c_color: %s\n", map.c_color);
	ft_printf("=====\n");
	i = -1;
	while (++i < map.size)
		ft_printf("%s\n", map.tab[i]);
	ft_printf("=====\n");
}

void	free_map(t_map map)
{
	int	i;

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
	i = -1;
	if (map.tab)
	{
		while (++i < map.size)
		{
			free(map.tab[i]);
		}
		free(map.tab);
	}
}

int main(void)
{
	int		fd;
	t_map	map;
	int		line = 1;
	int		start = 0;
	int		tab_len = 0;
	char	*tmp;
	char	*trimmed;
	char	map_file[100] = "./map/first_map.cub";

	fd = open(map_file, O_RDONLY);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		trimmed = ft_strtrim(tmp, "\n");
		free(tmp);
		if (!ft_strncmp(trimmed, "NO", 2))
			map.m_no = ft_strdup(trimmed);
		else if (!ft_strncmp(trimmed, "SO", 2))
			map.m_so = ft_strdup(trimmed);
		else if (!ft_strncmp(trimmed, "WE", 2))
			map.m_we = ft_strdup(trimmed);
		else if (!ft_strncmp(trimmed, "EA", 2))
			map.m_ea = ft_strdup(trimmed);
		else if (!ft_strncmp(trimmed, "F ", 2))
			map.f_color = ft_strdup(trimmed);
		else if (!ft_strncmp(trimmed, "C ", 2))
			map.c_color = ft_strdup(trimmed);
		else if (ft_strchr(trimmed, '1') || ft_strchr(trimmed, '0'))
		{
			if (start == 0)
				start = line;
			tab_len++;
		}
		if (trimmed)
			free(trimmed);
		line++;
	}
	close(fd);
	fd = open(map_file, O_RDONLY);
	int	i = 0;
	map.tab = malloc(sizeof(char *) * (tab_len));
	map.size = tab_len - 1;
	if (!map.tab)
		exit(EXIT_FAILURE);
	int	j = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		if (i < start)
		{
			i++;
			free(tmp);
			continue;
		}
		trimmed = ft_strtrim(tmp, "\n");
		free(tmp);
		if (ft_strchr(trimmed, '1') || ft_strchr(trimmed, '0'))
		{
			map.tab[j++] = ft_strdup(trimmed);
		}
		if (trimmed)
			free(trimmed);
		line++;
	}
	close(fd);
	print_map(map);
	ft_printf("tab_len: %d\n", tab_len);
	ft_printf("start: %d\n", start);
	free_map(map);
}