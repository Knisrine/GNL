#ifndef GET_NLB_H
# define GET_NLB_H

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <stdio.h>
#include <fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>

char	*get_next_line(int fd);
void	*ft_memcpy(char *dst,  char *src, size_t n);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strdup(const char *s1);
int		ft_strlen( char *str);
char	*ft_strchr(char *scanned, int searched);

char    *ext_line(char *s);
char	*rest_of_string(char *s);
char *the_string(char *s, int fd);

#endif