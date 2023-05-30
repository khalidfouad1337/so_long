/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:04:41 by kfouad            #+#    #+#             */
/*   Updated: 2023/05/27 16:57:41 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
# include <fcntl.h>
#include "get_next_line/get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	c = (char *)s;
	i = 0;
	if (!c)
		return ;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}

void	*ft_calloc(int count, int size)
{
	char	*p;
	int	r;

	r = count * size;
	p = malloc(r);
	if (p == 0)
		return (0);
	else
		ft_bzero(p, r);
	return (p);
}

char	*ft_substr(char  *s, unsigned int start, int len)
{
	char	*p;
	char	*s1;
	int	i;
	int	n;

	s1 = (char *)s;
	i = 0;
	n = len;
	if (start > ft_strlen(s1) || !s1)
		return (ft_calloc(1, 1));
	else if (len > ft_strlen(s1) - start)
		n = ft_strlen(s1) - start;
	p = malloc(n + 1);
	while (s1[i] && i < n)
	{
		p[i] = s1[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	chhal_mn_klma(char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			j++;
		i++;
	}
	return (j + 1);
}

char	**ft_split(char  *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	result = malloc((chhal_mn_klma((char *)s, c) + 1) * sizeof(char *));
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		if (j != i)
			result[k++] = ft_substr(s, i, j - i);
		i = j;
	}
	result[k] = (char *) '\0';
	return (result);
}


char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*p;
	int		i;

	s = (char *)s1;
	p = (char *)malloc ((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int len_map(int fd)
{
    int len;

    len = 0;
    while(get_next_line(fd))   
        len++;
    close(fd);
    return (len);
}

int main(int ac, char **av)
{
    int fd;
    int i;
    int len;
    char *raw_map;
    char    **map;
    char *line;
    
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
    printf("%d\n", check_size_map(map));
    printf("%d\n", check_wall_map(map));
    // {
    //     printf("%s\n", ptr[i]);
    //    i++;
    // }
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

// void ft_check_name(char *str)
// {
//     int i;
    
//     i = 0;
//     while (str[i] != '.' && str[i] != '\0')
//         i++;
//     if (ft_strncmp(&str[i], ".ber", 4) == 1)
//         print_error(2);
// }