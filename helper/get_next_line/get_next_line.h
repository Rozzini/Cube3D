/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:19:34 by gabdoush          #+#    #+#             */
/*   Updated: 2022/09/06 11:54:49 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

char	*get_next_line(int fd);
char	*ft_search_new_line(char *buffer);
char	*ft_reading_buffer(int fd, char *edited_buffer);
char	*ft_get_next_text(char *buffer);
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *edited_buffer, char *buff);
char	*ft_strchr_gnl(char *s, int c);

#endif
