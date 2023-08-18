/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:24:30 by pvong             #+#    #+#             */
/*   Updated: 2023/03/08 14:53:42 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	a;

	if (argc < 3 && argv[1][1] == '\0')
	{
		a = argv[1][0];
		printf("Before ft: %c\n", a);
		a = ft_toupper(a);
		printf("After ft: %c\n", a);
	}
	return (0);
}
*/
