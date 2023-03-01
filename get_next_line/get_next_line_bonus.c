/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:36:23 by kfouad            #+#    #+#             */
/*   Updated: 2022/12/07 14:54:45 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *save)
{
	int			readline;
	char		buf[BUFFER_SIZE + 1];

	readline = 1;
	while (readline > 0 && !ft_strchr(save, '\n'))
	{
		readline = read(fd, buf, BUFFER_SIZE);
		if (readline < 0)
		{
			free(save);
			return (0);
		}
		buf[readline] = '\0';
		save = ft_strjoin(save, buf);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (0);
	save[fd] = ft_read(fd, save[fd]);
	if (!save[fd])
		return (0);
	if (ft_strlen(save[fd]) >= 0)
	{
		line = newline(save[fd]);
		save[fd] = cutline(save[fd]);
		return (line);
	}
	return (NULL);
}
