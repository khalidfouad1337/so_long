/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:04:41 by kfouad            #+#    #+#             */
/*   Updated: 2023/03/01 00:36:42 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
# include <fcntl.h>
#include "get_next_line/get_next_line.h"
int main()
{
    int fd;
    int i;
    char **ptr;
    char *pt;
    i = 0;
    fd = open("map.ber", O_RDWR);
    while (get_next_line(fd))
        i++;
    close(fd);
    fd = open("map.ber", O_RDWR);
    ptr = malloc((i + 1) * sizeof (char *));
    i = 0;
    pt = get_next_line(fd);
    while (pt)
    {
        ptr[i++] = pt;
        pt = get_next_line(fd);
    }
    ptr[i] = 0;
    i = 0;
    int j = 0;
    while (ptr[i])
    {
        j = 0;
        while(ptr[i][j])
        {
            if (ptr[i][j] == '\n')
                ptr[i][j] = '\0';
            j++;
        }
        i++;
    }
    i =0;
    while(ptr[i])
    {
        printf("%s\n", ptr[i]);
       i++;
    }
}