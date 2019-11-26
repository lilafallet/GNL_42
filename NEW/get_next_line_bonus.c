/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:24:26 by lfallet           #+#    #+#             */
/*   Updated: 2019/11/26 21:24:41 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static ssize_t		contained_newline(char *rest)
{
	ssize_t	i;

	i = 0;
	if (rest == NULL)
		return (-1);
	while (rest[i] != '\0')
	{
		if (rest[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		get_rest(char **rest, char **line)
{
	char	*tmp;
	ssize_t	i;
	int		ret;

	ret = 0;
	if (*rest == NULL)
		return (ret);	
	i = contained_newline(*rest);
	tmp = NULL;
	if (**rest != '\0')
	{
		ret = 1;
		if (i == -1)
			*line = ft_strjoinfree(line, rest, FREE_S2);
		else
		{
			tmp = ft_strndup(*rest, i);
			*line = ft_strjoinfree(line, &tmp, FREE_S2); 
			tmp = ft_strndup(*rest + i + 1, ft_strlen(*rest + i + 1));
		}
	}
	free(*rest); 
	*rest = tmp;
	return (ret);
}

static int		read_line(int fd, char **rest, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;
	char	*ptr_buff;
	char	*keep;

	keep = *rest;
	ft_memset(buff, 0, BUFFER_SIZE + 1); 
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0) 
	{
		buff[BUFFER_SIZE] = '\0';
		ptr_buff = buff;
		*rest = ft_strjoinfree(rest, &ptr_buff, FREE_S1); 
		ft_memset(buff, 0, BUFFER_SIZE + 1); 
		if (contained_newline(*rest) != -1) 
			break ;
	}
	if (ret == 0 && (keep == NULL || *keep == '\0'))
	{
		get_rest(rest, line); 
		free(*rest); 
		return (0);
	}
	return ((ret != -1 && *rest != NULL) ? get_rest(rest, line) : ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest[1025] = {0};
	int			ret;

	ret = -1;
	if (fd >= 0 && fd < 1025 && BUFFER_SIZE > 0)
	{
		*line = NULL;
		ret = get_rest(&rest[fd], line); 
		if (rest[fd] == NULL || *line == NULL)
			ret = read_line(fd, &rest[fd], line); 
	}
	return (ret);	
}
