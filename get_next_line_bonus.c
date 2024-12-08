/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:57:00 by nikhtib           #+#    #+#             */
/*   Updated: 2024/12/08 21:13:03 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str && str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen((char *)s1);
	ptr = malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

char	*read_line(int fd, char *s)
{
	char	*buffer;
	int		srd;

	srd = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(s), s = NULL, NULL);
	while (srd > 0 && !ft_strchr(s, '\n'))
	{
		srd = read(fd, buffer, BUFFER_SIZE);
		if (srd == -1)
			return (free(s), s = NULL, free(buffer), NULL);
		buffer[srd] = '\0';
		if (!srd)
			continue ;
		s = ft_strjoin(s, buffer);
	}
	free(buffer);
	if (srd == 0 && (!s || *s == '\0'))
		return (free(s), s = NULL, NULL);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*nl;
	static char	*s[10240];

	if (fd < 0)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(s[fd]), s[fd] = NULL, NULL);
	s[fd] = read_line(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	nl = ext_line(s[fd]);
	s[fd] = rest_of_string(s[fd]);
	return (nl);
}
