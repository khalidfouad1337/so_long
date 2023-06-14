/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:04:41 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/14 21:32:22 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
			free(data->map[i++]);
	}
	i = 0;
	if (data->map2)
	{
		while (data->map2[i])
			free(data->map2[i++]);
	}
}

int	ft_close(t_data *data)
{
	// data++;
	free_maps(data);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac != 2)
		print_error(0);
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		print_error(1);
	data.len = len_map(fd);
	data.map = 0;
	data.map2 = 0;
	ft_read_map(&data, av[1]);
	data.map = ft_split(data.raw_map, '\n');
	free(data.raw_map);
	playerxy(&data);
	if (!ft_valide_map(&data, av[1]))
		free_maps(&data);
	get_widht_hieght(&data);
	init_mlx(&data);
	mlx_key_hook(data.v_mlx.mlx_win, ft_move, &data);
	// ft_printf("clt --> %d\n", data.nbr_coll);
	mlx_hook(data.v_mlx.mlx_win, 17, 0, ft_close, &data);
	mlx_loop(data.v_mlx.mlx);
}
