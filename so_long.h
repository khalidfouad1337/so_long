/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:16:56 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/15 13:04:57 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_mlx_v
{
	void	*mlx;
	void	*mlx_win;
	void	*img_player;
	void	*img_wall;
	void	*img_coll;
	void	*img_door;
	int		img_width;
	int		img_height;
}t_mlx_v;

typedef struct s_data
{
	int		height;
	int		width;
	int		len;
	char	*raw_map;
	char	**map;
	char	**map2;
	char	*line;
	t_mlx_v	v_mlx;
	int		xplayer;
	int		yplayer;
	int		ex;
	int		ey;
	int		nbr_coll;
	int		nbr_mv;
}	t_data;

typedef struct s_parm
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	j;
}	t_parm;

int		ft_printf(const char *format, ...);
int		ft_strncmp( char *s1, char *s2, int n);
void	print_error(int n);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(int count, int size);
char	*ft_substr(char	*s, int start, int len);
int		chhal_mn_klma(char *s, char c);
char	**ft_split(char	*s, char c);

int		ft_valide_map(t_data *data, char *file);
int		len_map(int fd);
int		check_x(char **map);
void	ft_duplicate_map(t_data *data);
void	ft_read_map(t_data *data, char *file);
void	get_widht_hieght(t_data *data);
int		check_size_map(char **ptr);
int		check_wall_map(char **ptr);
int		ft_check_name(char *str);
int		validation_map1(char **str);
void	playerxy(t_data *data);
void	validation_path(t_data *data, int x, int y);

void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);
void	init_mlx(t_data *data);
void	ft_drawer(t_data *data);
int		ft_move(int key, t_data *data);
void	free_maps(t_data *data);
void	free_images(t_data *data);
#endif
