/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:50:20 by pvong             #+#    #+#             */
/*   Updated: 2022/10/19 11:56:12 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_sep(char c, char compare)
{
	if (c == compare)
		return (1);
	return (0);
}

size_t	ft_get_words_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && !(ft_is_sep(s[i], c)))
		i++;
	return (i);
}

size_t	ft_get_nb_words(char const *s, char c)
{
	size_t	i;
	size_t	words;
	size_t	len;

	i = 0;
	len = 0;
	words = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] && (ft_is_sep(s[i], c)))
			i++;
		len = ft_get_words_len(&s[i], c);
		i += len;
		if (len)
			words++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	nb_words;
	size_t	j;

	nb_words = ft_get_nb_words(s, c);
	str = ft_calloc(nb_words + 1, sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] && !(ft_is_sep(s[i], c)))
		{
			str[j] = ft_substr(s, i, ft_get_words_len(s + i, c));
			i += ft_get_words_len(s + i, c);
			j++;
		}
		i++;
	}
	str[nb_words] = 0;
	return (str);
}
