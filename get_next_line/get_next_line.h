/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:21:32 by kfouad            #+#    #+#             */
/*   Updated: 2023/03/01 00:16:36 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # include <fcntl.h>
# include <unistd.h>
//# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_strchr(char	*save, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *save, char *buf);
char	*newline(char *save);
char	*cutline(char *save);

#endif
