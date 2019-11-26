/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:28:57 by lfallet           #+#    #+#             */
/*   Updated: 2019/11/26 14:17:33 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_file
{
	char		*rest;
	int			fd;
}					t_file;

t_file				*get_file(t_list **lst, int fd);
void				del(t_list **lst, t_file *file);

#endif
