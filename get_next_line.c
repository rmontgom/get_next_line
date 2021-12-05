/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:27:38 by rmontgom          #+#    #+#             */
/*   Updated: 2021/12/05 18:44:01 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_str(int fd, char *next_str)
{
	char	*buf;
	int		read_bt;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bt = 1;
	while (!ft_strchr(next_str, '\n') && read_bt > 0)
	{
		read_bt = read(fd, buf, BUFFER_SIZE);
		if (read_bt == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bt] = '\0';
		next_str = ft_strjoin(next_str, buf);
	}
	free(buf);
	return (next_str);
}

char	*ft_get_line(char *next_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!next_str[i])
		return (NULL);
	while (next_str[i] && next_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (next_str[i] && next_str[i] != '\n')
	{
		str[i] = next_str[i];
		i++;
	}
	if (next_str[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_newstr(char *next_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (next_str[i] && next_str[i] != '\n')
		i++;
	if (!next_str[i])
	{
		free(next_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(next_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (next_str[i])
		str[j++] = next_str[i++];
	str[j] = '\0';
	free(next_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*next_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_str = ft_read_str(fd, next_str);
	if (!next_str)
		return (NULL);
	line = ft_get_line(next_str);
	next_str = ft_get_newstr(next_str);
	return (line);
}
