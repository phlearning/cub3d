/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:34:30 by pvong             #+#    #+#             */
/*   Updated: 2023/03/08 14:52:03 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char** argv)
{
	if (argc < 3)
		printf("Is %s digit ? 1 = Yes 0 = No\n Isdigit: %d\n", \
				argv[1], ft_isdigit(argv[1][0]));
	return (0);
}
*/
