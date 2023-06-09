/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:04:41 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/09 20:06:24 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_widht_hieght(t_data *data, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
			j++;
		data->width = j;
		i++;
	}
	data->height = i;
}

int main(int ac, char **av)
{
    int fd;
    int i;
    int len;
    char *raw_map;
    char    **map;
	 char    **map2;
    char *line;
    void	*mlx;
	void	*mlx_win;
	void	*img_player;
	void	*img_wall;
	int j = 0;
	t_data data;
	
    fd = open("map.ber", O_RDWR);
    i = 0;
    raw_map = ft_calloc(1, 1);
    len = len_map(fd);
    fd = open("map.ber", O_RDWR);
    while (i < len)
    {
        line = get_next_line(fd);
        raw_map = ft_strjoin(raw_map, line);
        free(line);
        i++;
    }
    i = 0;
    map = ft_split(raw_map, '\n');
    free(raw_map);
    while (map[i] != 0)
    {
        printf("%s\n", map[i++]);
    }
    // printf("%d\n", check_size_map(map));
    // printf("%d\n", check_wall_map(map));
    // {
    //     printf("%s\n", ptr[i]);
    //    i++;
    // }
	int x;
	int y;
	int img_width;
	int img_height;
	int img_width2;
	int img_height2;
	
	playerxy(map, &x, &y);
	printf("%d\t%d\t%d\t%d\n", x, y, len, ft_strlen(map[0]));
	i = 0;
	map2 = malloc((len + 1) * sizeof(char *));
	while(map[i])
	{
		map2[i] = ft_strdup(map[i]);
		i++;
	}
	map2[i] = NULL;
	validation_path(map, len, ft_strlen(map[0]), x, y);
	if (!check_x(map))
	{
		print_error(1);
	}
	if (check_size_map(map) == 0)
	{
		printf("erroe in len map\n");
		exit(1);
	}
	i = 0;
	// while (map[i] != 0)
    // {
    //     printf("%s\n", map[i++]);
    // }
	get_widht_hieght(&data, map);
	mlx = mlx_init();
	
	img_player = mlx_xpm_file_to_image(mlx, "player.xpm", &img_width, &img_height);
	img_wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &img_width2, &img_height2);
	mlx_win = mlx_new_window(mlx, img_width2 * data.width, img_height2 * data.height, "Hello world!");
	// img = mlx_xpm_file_to_image(mlx, "player.xpm", &img_width, &img_height);
	i = 0;
	
	while(map2[i])
	{
		j = 0;
		while(map2[i][j])
		{
			if (map2[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, img_player , j * img_width, i * img_height);
			if (map2[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img_wall, j * img_width2, i * img_height2);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
