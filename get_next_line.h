/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschofer <sschofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:55:29 by sschofer          #+#    #+#             */
/*   Updated: 2022/06/30 17:09:01 by sschofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*the_reader(char *storage);
char	*line_transfer(char *storage);
char	*ft_strchr(const char *s, int c);
size_t	ft_lenton(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);



#endif

