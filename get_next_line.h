/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:20:42 by aaouassa          #+#    #+#             */
/*   Updated: 2022/11/18 09:42:05 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include<limits.h>
# include<fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_line(char *stach);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*get_next(int fd, char *stach);
char	*ft_rest(char *rst);
char	*free_it(char *c);
#endif