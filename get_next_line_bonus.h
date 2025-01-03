/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 05:56:58 by nikhtib           #+#    #+#             */
/*   Updated: 2024/12/08 20:20:00 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*ft_memcpy(char *dst, char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
int		ft_strlen(char *str);
char	*ft_strchr(char *scanned, int searched);
char	*ext_line(char *s);
char	*rest_of_string(char *s);
#endif