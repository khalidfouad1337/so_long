/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:23:13 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/15 13:13:34 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	print_error(int n)
{
	ft_printf("Eroor\n");
	if (n == 0)
	{
		ft_printf("Eroor in arguments input");
		exit(0);
	}
	if (n == 1)
	{
		ft_printf("invalid syntax of name map file");
		exit(1);
	}
	else if (n == 2)
		ft_printf("invalid name file");
	if (n == 3)
		ft_printf("invalid map");
}
