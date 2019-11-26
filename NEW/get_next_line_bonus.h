/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:23:49 by lfallet           #+#    #+#             */
/*   Updated: 2019/11/26 21:24:16 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define FREE_S1 1
# define FREE_S2 2

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strjoinfree(char **s1, char **s2, int is_free);
char				*ft_strndup(const char *s, size_t size);
void				*ft_memset(void *s, int c, size_t n);

#endif
