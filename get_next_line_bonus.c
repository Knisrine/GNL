/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:57:00 by nikhtib           #+#    #+#             */
/*   Updated: 2024/12/07 20:46:47 by nikhtib          ###   ########.fr       */
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
	char		buffer[BUFFER_SIZE + 1];
	char		*nl;
	int			srd;
	static char	*s[10240];

	srd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (s[fd])
			return (free(s[fd]), s[fd] = NULL, NULL);
		return (NULL);
	}
	while (srd > 0 && !ft_strchr(s[fd], '\n'))
	{
		srd = read(fd, buffer, BUFFER_SIZE);
		buffer[srd] = '\0';
		if (!srd)
			continue ;
		s[fd] = ft_strjoin(s[fd], buffer);
	}
	if (srd == 0 && (!s[fd] || *s[fd] == '\0'))
		return (free(s[fd]), s[fd] = NULL, NULL);
	return (nl = ext_line(s[fd]), s[fd] = rest_of_string(s[fd]), nl);
}
// int main()
// 	{
// 	char *line01;
//     char *line02;
// 	int i = 0;
// 	// exit(1);
// 	// int fd = open("file.txt",O_CREAT | O_RDWR ,0777);
// 	int fd1 = open("file1.txt", O_CREAT | O_RDWR, 0777);
// 	// int fd2 = open("file2.txt", O_CREAT | O_RDWR, 0777);
// 	if(fd1 < 0)
// 		printf("error\n");
// 	// if(fd2 < 0)
// 	// 	printf("error\n");
//     while(i < 1)
// 	{
// 	line01 = get_next_line(fd1);
//     // line02 = get_next_line(fd2);
// 	printf("+%s",line01);
// 	system("leaks a.out");
// 	// printf("+%s",line02);
// 		i++;
// 	}
// 	close(fd1);
// 	// close(fd2);
// }