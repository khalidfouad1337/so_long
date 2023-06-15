/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:07:56 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/15 13:07:50 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_images(t_data *data)
{
	mlx_destroy_image(data->v_mlx.mlx, data->v_mlx.img_coll);
	mlx_destroy_image(data->v_mlx.mlx, data->v_mlx.img_player);
	mlx_destroy_image(data->v_mlx.mlx, data->v_mlx.img_wall);
	mlx_destroy_image(data->v_mlx.mlx, data->v_mlx.img_door);
	mlx_destroy_window(data->v_mlx.mlx, data->v_mlx.mlx_win);
	exit(0);
}

void	init_mlx(t_data *data)
{
	data->v_mlx.mlx = mlx_init();
	data->v_mlx.img_player = mlx_xpm_file_to_image(data->v_mlx.mlx, \
		"assets/player.xpm", &data->v_mlx.img_width, &data->v_mlx.img_height);
	data->v_mlx.img_wall = mlx_xpm_file_to_image(data->v_mlx.mlx, \
		"assets/wall.xpm", &data->v_mlx.img_width, &data->v_mlx.img_height);
	data->v_mlx.img_coll = mlx_xpm_file_to_image(data->v_mlx.mlx, \
		"assets/coll.xpm", &data->v_mlx.img_width, &data->v_mlx.img_height);
	data->v_mlx.img_door = mlx_xpm_file_to_image(data->v_mlx.mlx, \
		"assets/door.xpm", &data->v_mlx.img_width, &data->v_mlx.img_height);
	data->v_mlx.mlx_win = mlx_new_window(data->v_mlx.mlx, data->v_mlx.img_width \
		* data->width, data->v_mlx.img_height * data->height, "so_long");
	ft_drawer(data);
}

void	ft_print_image(t_data *data, void *image, int i, int j)
{
	mlx_put_image_to_window(data->v_mlx.mlx, data->v_mlx.mlx_win, \
					image, j * data->v_mlx.img_width, \
						i * data->v_mlx.img_height);
}

void	ft_drawer(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(data->v_mlx.mlx, data->v_mlx.mlx_win);
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (i == data->ex && j == data->ey && data->map[i][j] != 'E'
				&& data->map[i][j] != 'P')
				data->map[i][j] = 'E';
			if (data->map[i][j] == 'P')
				ft_print_image(data, data->v_mlx.img_player, i, j);
			if (data->map[i][j] == '1')
				ft_print_image(data, data->v_mlx.img_wall, i, j);
			if (data->map[i][j] == 'C')
				ft_print_image(data, data->v_mlx.img_coll, i, j);
			if (data->map[i][j] == 'E')
				ft_print_image(data, data->v_mlx.img_door, i, j);
		}
	}
}
