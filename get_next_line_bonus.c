/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:57:00 by nikhtib           #+#    #+#             */
/*   Updated: 2024/12/08 15:25:21 by nikhtib          ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*nl;
	int			srd;
	static char	*s[10240];

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (s[fd])
			return (free(s[fd]), s[fd] = NULL,free(buffer), NULL);
		return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	srd = 1;
	while (srd > 0 && !ft_strchr(s[fd], '\n'))
	{
		srd = read(fd, buffer, BUFFER_SIZE);
		buffer[srd] = '\0';
		if (!srd)
			continue ;
		s[fd] = ft_strjoin(s[fd], buffer);
	}
	free(buffer);
	if (srd == 0 && (!s[fd] || *s[fd] == '\0'))
		return (free(s[fd]), s[fd] = NULL, NULL);
	return (nl = ext_line(s[fd]), s[fd] = rest_of_string(s[fd]), nl);
}
// #include <fcntl.h>
// #include <stdio.h>

// int main()
// 	{
// 	// exit(1);
// 	// int fd = open("file.txt",O_CREAT | O_RDWR ,0777);
// 	int fd1 = open("file1.txt", O_CREAT | O_RDWR, 0777);
// 	int fd2 = open("file2.txt", O_CREAT | O_RDWR, 0777);
	
// 	char *line01 = get_next_line(fd1);
// 	// exit(1);
//     char *line02 = get_next_line(fd2);
//     while(line01 || line02)
// 	{
// 	printf("+from file 1 -->%s",line01);
// 	printf("+from file 2 --->%s",line02);
// 	free(line01);
// 	free(line02);
// 	line01 = get_next_line(fd1);
//     line02 = get_next_line(fd2);
// 	// printf("+%s",line01);
// 	// system("leaks a.out");
// 	}
// 	close(fd1);
// 	close(fd2);
// }