/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:20:07 by aaouassa          #+#    #+#             */
/*   Updated: 2022/11/17 11:53:47 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*copy;
	char	*s_s;
	int		i;

	if (!s1)
		return (NULL);
	s_s = (char *)s1;
	i = 0;
	while (s1[i] != '\0')
		i++;
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (!(copy))
		return (NULL);
	i = 0;
	while (s_s[i])
	{
		copy[i] = s_s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sf;
	int		i;
	int		j;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	sf = malloc(sizeof(char) * (i + j) + 1);
	if (!sf)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		sf[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		sf[i++] = s2[j++];
	}
	sf[i] = '\0';
	return (sf);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	c1;

	c1 = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			return ((char *)s + i);
		i++;
	}
	if (c1 == '\0')
		return ((char *)s + i);
	return (NULL);
}
char    *free_it(char *c)
{
    free(c);
    return (NULL);
}