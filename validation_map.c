/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:01:52 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/09 17:12:53 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int len_map(int fd)
{
    int len;

    len = 0;
    while(get_next_line(fd))   
        len++;
    close(fd);
    return (len);
}

int check_size_map(char **ptr)
{
    int size;
    int i;

    size = ft_strlen(ptr[0]);
    i = 0;
    while (ptr[++i])
    {
        if (size != ft_strlen(ptr[i]))
            return (0);
    }
    return (1);
}

int check_wall_map(char **ptr)
{
    int hight;
    int j;
    int i;
    int size;

    j = -1;
    hight = 0;
    size = ft_strlen(ptr[0]) - 1;
    
    while(ptr[hight])
        hight++;
    while (ptr[++j])
    {
        if (ptr[j][0] != '1' || ptr[j][size] != '1')
            return (0);
        i = -1;
        while ((j == 0 || j == hight - 1) && ptr[j][++i])
        {
            if (ptr[j][i] != '1')
                return (0);
        }
    }
    return (1);
}

void ft_check_name(char *str)
{
    int i;
    
    i = 0;
	while (str[i])
		i++;
    while (str[i] != '.' && i > 0)
        i--;
	if (str[i] == '.')
		i--;
    if (ft_strncmp(&str[i], ".ber", 4) == 1)
        print_error(2);
}


void	validation_map1(char **str)
{
	int p;
	int e;
	int c;
	int i;
	int j;
	
	p = 0;
	e = 0;
	c = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[++i][j])
		{
			if (str[i][j] == 'P')
				p++;
			if (str[i][j] == 'E')
				e++;
			if (str[i][j] == 'C')
				c++;
		}
	}
	if (p != 1 || e != 1 || c < 1)
	print_error(1);
}