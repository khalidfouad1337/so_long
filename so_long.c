/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:04:41 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/11 19:20:35 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"





int ft_close(t_data *data)
{
	data++;
	exit(0);
	return 0;
}
 
int main(int ac, char **av)
{
    int fd;

    t_data data;
	if (ac == 1)
		print_error(1);
	av[1] = "map.ber";
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		print_error(1);
    data.len = len_map(fd);
	ft_read_map(&data,av[1]);
    data.map = ft_split(data.raw_map, '\n');
	free(data.raw_map);
	ft_valide_map(&data, av[1]);
	playerxy(&data);
	get_widht_hieght(&data);
	init_mlx(&data);
	mlx_key_hook(data.v_mlx.mlx_win, ft_move, &data);
	ft_printf("clt --> %d\n",data.nbr_coll);
	mlx_hook(data.v_mlx.mlx_win, 17, 0, ft_close, &data);
	mlx_loop(data.v_mlx.mlx);
}