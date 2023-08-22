/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:51:14 by pvong             #+#    #+#             */
/*   Updated: 2023/08/22 15:37:17 by pvong            ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}	t_data;

#endif