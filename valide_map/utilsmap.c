/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:07:20 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/12 14:41:49 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	len_map(int fd)
{
	int	len;

	len = 0;
	while (get_next_line(fd))
		len++;
	close(fd);
	return (len);
}

void	get_widht_hieght(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		data->width = j;
		i++;
	}
	data->height = i;
}

void	ft_read_map(t_data *data, char *file)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file, O_RDWR);
	data->raw_map = ft_calloc(1, 1);
	while (i < data->len)
	{
		data->line = get_next_line(fd);
		data->raw_map = ft_strjoin(data->raw_map, data->line);
		free(data->line);
		i++;
	}
}

void	ft_duplicate_map(t_data *data)
{
	int	i;

	i = 0;
	data->map2 = malloc((data->len + 1) * sizeof(char *));
	while (data->map[i])
	{
		data->map2[i] = ft_strdup(data->map[i]);
		i++;
	}
	data->map2[i] = NULL;
}
