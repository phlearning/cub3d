/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:49:09 by pvong             #+#    #+#             */
/*   Updated: 2023/03/08 14:51:48 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || \
			(c >= '0' && c <= '9'))
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
		printf("Is %s alnum ? 1 = Yes 0 = No\n Isalnum: %d\n", \
				argv[1], ft_isalnum(argv[1][0]));
	return (0);
}
*/
