/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:08:25 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/15 13:10:18 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_move(int key, t_data *data)
{
	if (key == 126 || key == 13)
		ft_move_up(data);
	if (key == 125 || key == 1)
		ft_move_down(data);
	if (key == 123 || key == 0)
		ft_move_left(data);
	if (key == 124 || key == 2)
		ft_move_right(data);
	if (key == 53)
	{
		free_maps(data);
		free_images(data);
	}
	ft_drawer (data);
	return (0);
}

void	ft_move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->xplayer;
	y = data->yplayer;
	if (data->map[x - 1][y] == 'E' && data->nbr_coll == 0)
	{
		free_maps(data);
		free_images(data);
	}
	else if (data->map[x - 1][y] != '1')
	{
		if (data->map[x - 1][y] == 'C')
			data->nbr_coll--;
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'P';
		data->xplayer = x - 1;
		data->nbr_mv++;
		ft_printf("nbr de movs --> %d\n", data->nbr_mv);
	}
}

void	ft_move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->xplayer;
	y = data->yplayer;
	if (data->map[x + 1][y] == 'E' && data->nbr_coll == 0)
	{
		free_maps(data);
		free_images(data);
	}
	else if (data->map[x + 1][y] != '1')
	{
		if (data->map[x + 1][y] == 'C')
			data->nbr_coll--;
		data->map[x][y] = '0';
		data->map[x + 1][y] = 'P';
		data->xplayer = x + 1;
		data->nbr_mv++;
		ft_printf("nbr de movs --> %d\n", data->nbr_mv);
	}
}

void	ft_move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->xplayer;
	y = data->yplayer;
	if (data->map[x][y - 1] == 'E' && data->nbr_coll == 0)
	{
		free_maps(data);
		free_images(data);
	}
	else if (data->map[x][y - 1] != '1')
	{
		if (data->map[x][y - 1] == 'C')
			data->nbr_coll--;
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'P';
		data->yplayer = y - 1 ;
		data->nbr_mv++;
		ft_printf("nbr de movs --> %d\n", data->nbr_mv);
	}
}

void	ft_move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->xplayer;
	y = data->yplayer;
	if (data->map[x][y + 1] == 'E' && data->nbr_coll == 0)
	{
		free_maps(data);
		free_images(data);
	}
	else if (data->map[x][y + 1] != '1')
	{
		if (data->map[x][y + 1] == 'C')
			data->nbr_coll--;
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'P';
		data->yplayer = y + 1;
		data->nbr_mv++;
		ft_printf("nbr de movs --> %d\n", data->nbr_mv);
	}
}
