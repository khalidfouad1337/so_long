/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:02:59 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/13 20:04:29 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	playerxy(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->nbr_mv = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->xplayer = i;
				data->yplayer = j;
			}
			if (data->map[i][j] == 'E')
			{
				data->ex = i;
				data->ey = j;
			}
			j++;
		}
		i++;
	}
}

void	validation_path(t_data *data, int x, int y)
{
	int	length;
	int	width;

	length = data->len;
	width = ft_strlen(data->map2[0]);
	if (x >= 0 && x < length && y >= 0 && y < width
		&& data->map2[x][y] != '1' && data->map2[x][y] != 'X')
	{
		data->map2[x][y] = 'X';
		validation_path(data, x - 1, y);
		validation_path(data, x + 1, y);
		validation_path(data, x, y - 1);
		validation_path(data, x, y + 1);
	}
	return ;
}

int	check_x(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
