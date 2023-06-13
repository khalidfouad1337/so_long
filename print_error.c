/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:23:13 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/12 16:53:24 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int n)
{
	ft_printf("Eroor\n");
	if (n == 1)
		ft_printf("invalid syntax of name map file");
	else if (n == 2)
		ft_printf("invalid name file");
	exit(1);
}
