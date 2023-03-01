/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:25:01 by kfouad            #+#    #+#             */
/*   Updated: 2022/12/02 22:34:31 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strchr(char	*save, int c)
{
	int		i;
	int		a;

	i = 0;
	if (!save)
		return (0);
	a = ft_strlen(save);
	while (i <= a)
	{
		if (save[i] == (char)c)
			return (&save[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *save, char *buf)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = (char *)malloc(((ft_strlen(save) + ft_strlen(buf)) \
							+ 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (save && save[i])
	{
		line[i] = save[i];
		i++;
	}
	while (buf[j])
	{
		line[i + j] = buf[j];
		j++;
	}
	line[i + j] = '\0';
	free(save);
	return (line);
}

char	*newline(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i] = save[i];
	if (save[i] == '\n')
		i++;
	line[i] = '\0';
	return (line);
}

char	*cutline(char *save)
{
	char	*cut;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	cut = malloc((ft_strlen(save) - i + 1) * sizeof(char));
	if (!cut)
		return (NULL);
	while (save[i])
		cut[j++] = save[i++];
	cut[j] = '\0';
	free(save);
	return (cut);
}
