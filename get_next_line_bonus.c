/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:57:00 by nikhtib           #+#    #+#             */
/*   Updated: 2024/12/06 18:08:26 by nikhtib          ###   ########.fr       */
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
	char		*buffer[10240];
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
		return NULL;
	}
	if (s == NULL)
		s = ft_strdup("");
		if(!s)
		return(NULL);
	while (srd > 0 && !ft_strchr(s, '\n'))
	{
		srd = read(fd, buffer[fd], BUFFER_SIZE);
		*buffer[srd] = '\0';
		if (!srd)
			continue ;
		s = ft_strjoin(s, buffer[fd]);
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
int main()
{
	// int fd = open("file.txt",O_CREAT | O_RDWR ,0777);
	int fd1 = open("file1.txt", O_CREAT | O_RDWR, 0777);
	int fd2 = open("file2.txt", O_CREAT | O_RDWR, 0777);
	if(fd1 < 0)
		printf("error\n");
	if(fd2 < 0)
		printf("error\n");
    
	char *line01 = get_next_line(fd1);
    char *line02 = get_next_line(fd2);
	printf("+%s",line01);
	printf("+%s",line02);
	close(fd1);
	close(fd2);
}