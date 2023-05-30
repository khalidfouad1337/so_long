/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:48:17 by kfouad            #+#    #+#             */
/*   Updated: 2023/05/14 18:48:19 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char	*s2, size_t	n)
{
	unsigned char	*str0;
	unsigned char	*str1;
	size_t			i;

	str0 = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str0[i] != '\0' && str0[i] == str1[i] && i < n - 1)
		i++;
	return (str0[i] - str1[i]);
}