/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:19:41 by aaouassa          #+#    #+#             */
/*   Updated: 2022/11/17 11:49:49 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_rest(char *rst)
{
	char	*stock;
	int		i;
	int		k;

	i = 0;
	if (!rst)
		return (NULL);
	while (rst[i] && rst[i] != '\n')
		i++;
	if (!rst[i])
		return (NULL);
	stock = malloc(sizeof(char) * ((ft_strlen(rst) - i) + 1));
	if (!stock)
		return (NULL);
	i++;
	k = 0;
	while (rst[i])
	{
		stock[k] = rst[i];
		k++;
		i++;
	}
	stock[k] = '\0';
	return (stock);
}

char	*ft_line(char *stline)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!stline || !stline[0])
		return (NULL);
	while (stline[i] && stline[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (stline[j] && j <= i)
	{
		line[j] = stline[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next(int fd, char *stach, char *s)
{
	char	*buff;
	int		rd;
	char	*tmp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	s = ft_strdup(stach);
	rd = 1;
	while (!ft_strchr(s, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(s);
			free_it(buff);
		}
		buff[rd] = '\0';
		tmp = ft_strjoin(s, buff);
		free (s);
		s = ft_strdup(tmp);
		free (tmp);
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*k;
	char		*tmp;
	static char	*h[10240];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	tmp = get_next(fd, h[fd], NULL);
	free (h[fd]);
	h[fd] = ft_strdup(tmp);
	free (tmp);
	if (!h[fd])
		return (NULL);
	k = ft_line(h[fd]);
	if (!ft_strlen(k))
	{
		free (h[fd]);
		h[fd] = NULL;
	}
	tmp = ft_rest(h[fd]);
	free (h[fd]);
	h[fd] = ft_strdup(tmp);
	free (tmp);
	return (k);
}
