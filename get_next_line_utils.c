/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:29:35 by rmontgom          #+#    #+#             */
/*   Updated: 2021/12/05 18:53:46 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *next_str, char *buf)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!next_str)
	{
		next_str = (char *)malloc(1 * sizeof(char));
		next_str[0] = '\0';
	}
	if (!next_str || !buf)
		return (NULL);
	str = (char *)malloc((ft_strlen(next_str) + ft_strlen(buf)
				+ 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (next_str)
		while (next_str[++i] != '\0')
			str[i] = next_str[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(next_str) + ft_strlen(buf)] = '\0';
	free(next_str);
	return (str);
}
