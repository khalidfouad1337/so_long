/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:14:04 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/12 16:14:07 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_valide_map(t_data *data, char *file)
{
	ft_check_name(file);
	if (!check_wall_map(data->map))
		print_error(1);
	data->nbr_coll = validation_map1(data->map);
	ft_duplicate_map(data);
	validation_path(data, data->xplayer, data->yplayer);
	if (check_size_map(data->map2) == 0)
		print_error(1);
}

int	check_size_map(char **ptr)
{
	int	size;
	int	i;

	size = ft_strlen(ptr[0]);
	i = 0;
	while (ptr[++i])
	{
		if (size != ft_strlen(ptr[i]))
			return (0);
	}
	return (1);
}

int	check_wall_map(char **ptr)
{
	int	hight;
	int	j;
	int	i;
	int	size;

	j = -1;
	hight = 0;
	size = ft_strlen(ptr[0]) - 1;
	while (ptr[hight])
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

void	ft_check_name(char *str)
{
	int	i;

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

int	validation_map1(char **str)
{
	t_parm	par;

	par.p = 0;
	par.e = 0;
	par.c = 0;
	par.i = -1;
	while (str[++par.i])
	{
		par.j = -1;
		while (str[par.i][++par.j])
		{
			if (str[par.i][par.j] == 'P')
				par.p++;
			if (str[par.i][par.j] == 'E')
				par.e++;
			if (str[par.i][par.j] == 'C')
				par.c++;
		}
	}
	if (par.p != 1 || par.e != 1 || par.c < 1)
		print_error(1);
	return (par.c);
}
