/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:00:05 by kfouad            #+#    #+#             */
/*   Updated: 2023/06/12 12:06:01 by kfouad           ###   ########.fr       */
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

char	*ft_substr(char  *s,  int start, int len)
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


