/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:02:59 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/09 17:12:56 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	playerxy(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
void	validation_path(char **map, int length, int width, int x, int y)
{
	if (x >= 0 && x < length && y >= 0 && y < width && map[x][y] != '1' && map[x][y] != 'X')
	{
		map[x][y] = 'X';
		validation_path(map, length, width, x - 1, y);
		validation_path(map, length, width, x + 1, y);
		validation_path(map, length, width, x, y - 1);
		validation_path(map, length, width, x, y + 1);
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