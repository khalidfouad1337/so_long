/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:48:17 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/12 16:54:33 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp( char *s1, char *s2, int n)
{
	char	*str0;
	char	*str1;
	int		i;

	str0 = (char *)s1;
	str1 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str0[i] != '\0' && str0[i] == str1[i] && i < n - 1)
		i++;
	return (str0[i] - str1[i]);
}
