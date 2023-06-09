/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:10:15 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/09 19:26:46 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
# include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct s_data
{
    int height;
    int width;
}           t_data;

int	ft_printf(const char *format, ...);
int	ft_strncmp( char *s1,  char	*s2, int	n);
void print_error(int n);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(int count, int size);
char	*ft_substr(char  *s, unsigned int start, int len);
int	chhal_mn_klma(char *s, char c);
char	**ft_split(char  *s, char c);
int len_map(int fd);
int check_size_map(char **ptr);
int check_wall_map(char **ptr);
void ft_check_name(char *str);
void	validation_map1(char **str);
void	playerxy(char **map, int *x, int *y);
void	validation_path(char **map, int length, int width, int x, int y);
int	check_x(char **map);

