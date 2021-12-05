/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:29:06 by rmontgom          #+#    #+#             */
/*   Updated: 2021/12/05 18:44:24 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *next_str, char *buf);
size_t	ft_strlen(const char *s);
char	*ft_get_line(char *next_str);
char	*ft_read_str(int fd, char *next_str);
char	*ft_strchr(char *s, int c);
char	*ft_get_newstr(char *next_str);
char	*ft_strdup(const char *s);

#endif