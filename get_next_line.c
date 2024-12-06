/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:10:36 by nikhtib           #+#    #+#             */
/*   Updated: 2024/12/06 19:14:15 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*nl;
	int			srd;
	static char	*s;

	srd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (s)
		{
			free(s);
			s = NULL;
		}
		return (NULL);
	}
	if (s == NULL)
		s = ft_strdup("");
		if(!s)
		return(NULL);
	while (srd > 0 && !ft_strchr(s, '\n'))
	{
		srd = read(fd, buffer, BUFFER_SIZE);
		buffer[srd] = '\0';
		if (!srd)
			continue ;
		s = ft_strjoin(s, buffer);
	}
	if (srd == 0 && (!s || *s == '\0'))
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	nl = ext_line(s);
	s = rest_of_string(s);
	return (nl);
}

// int main()
// {
// 	// int fd = open("file.txt",O_CREAT | O_RDWR ,0777);
// 	int fd = open("file.txt", O_CREAT | O_RDWR, 0777);
// 	if(fd < 0)
// 		printf("error\n");
// 	char *line = get_next_line(fd);
// 	printf("+%s",line);
// 	close(fd);
// }