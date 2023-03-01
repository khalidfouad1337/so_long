/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:28:44 by kfouad            #+#    #+#             */
/*   Updated: 2022/12/08 16:35:18 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//# include <fcntl.h>
# include <unistd.h>
//# include <stdio.h>
# include <stdlib.h>
//# include <limits.h>

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
