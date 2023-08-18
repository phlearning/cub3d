/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:22:46 by pvong             #+#    #+#             */
/*   Updated: 2023/03/11 13:48:20 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_read_error(int fd, char **buffer)
{
	if (read(fd, *buffer, 0))
	{
		free(*buffer);
		*buffer = 0;
		return (1);
	}
	return (0);
}

char	*ft_get_line(char **str, char **line)
{
	int		newlinepos;
	int		len;
	char	*tmp;

	if (!str || *str == 0)
		return (0);
	if (!ft_strchr(*str, '\n'))
	{
		*line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = 0;
		return (*line);
	}
	newlinepos = ft_strlen(ft_strchr(*str, '\n'));
	len = ft_strlen(*str);
	*line = ft_substr(*str, 0, len - newlinepos + 1);
	tmp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, len);
	free(tmp);
	if (**str == '\0')
	{
		free(*str);
		*str = 0;
	}
	return (*line);
}

// Lit le fichier jusqu'à trouver un newline dans le buffer
// et retourne ce qui a été lu
// Retourne NULL si rien n'est trouvé

void	ft_read_line(int fd, char *buffer, char **str)
{
	int		rd;
	char	*tmp;

	if (ft_free_read_error(fd, &buffer))
		return ;
	rd = read(fd, buffer, BUFFER_SIZE);
	buffer[rd] = '\0';
	while (rd > 0)
	{
		if (!*str)
			*str = ft_substr(buffer, 0, rd);
		else
		{
			tmp = *str;
			*str = ft_strjoin(*str, buffer);
			free(tmp);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
	}
	free(buffer);
}

//ret = read(fd, buf, buf_size)
//buf should be buf_size+1
//buf[ret] = '\0';

/* get_next_line prend en valeur un descripteur de fichier,
 * lit une ligne et retourne la ligne lue.
 * la fonction retourne NULL en cas d'erreur ou il ne reste
 * plus aucune ligne. */

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free(str);
		str = 0;
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(buffer);
		buffer = 0;
		return (NULL);
	}
	ft_read_line(fd, buffer, &str);
	line = ft_get_line(&str, &line);
	return (line);
}

/*----------------MAIN----------------*/
/*
int	main(void)
{
	int	fd;
	int	rd;

	fd = open("/Users/pvong/Desktop/exo/42cursus/doctest1.txt", O_RDONLY);
	rd = 1;
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd)); 
	printf("%s",get_next_line(fd)); 
	printf("%s",get_next_line(fd)); 
	printf("%s",get_next_line(fd)); 
	printf("%s",get_next_line(fd)); 
	printf("%s",get_next_line(fd)); 
	printf("%s",get_next_line(fd)); 
	printf("%s",get_next_line(fd)); 
	close(fd);
	return (0);
}
*/
