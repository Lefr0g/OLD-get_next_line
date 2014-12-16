/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:09:04 by amulin            #+#    #+#             */
/*   Updated: 2014/12/15 18:06:56 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	my_extend(char **dst, char **src)
{
	char	*buf;

	buf = (char*)malloc(sizeof(char) * (ft_strlen(*dst) + 1));
	ft_strcpy(buf, *dst);
	free(*dst);
	*dst = (char*)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(*src) + 1));
	ft_strcpy(*dst, buf);
	ft_strcat(*dst, *src);
	free(buf);
}

static int	my_check_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*keep;
	char		*tmp;
	char		*buf;
	ssize_t		ret;
	int			flag;
	int			lentoeol;
	int			remain;
	
	if (fd < 0 || line == NULL)
		return (-1);
	if (keep)
	{
		tmp = (char*)malloc(sizeof(char) * (ft_strlen(keep) + 1));
		ft_strcpy(tmp, keep);
	}
	else
	{
		tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		ft_bzero(tmp, BUFF_SIZE + 1);
	}
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	flag = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) && !flag)
	{
		if (ret == -1)
			return (-1);
		buf[BUFF_SIZE] = '\0';
		my_extend(&tmp, &buf);
		if ((lentoeol = my_check_eol(tmp)) >= 0)
			flag = 1;
	}
	if (ret == 0)
		return (0);
	*line = (char*)malloc(sizeof(char) * lentoeol);
	ft_strncpy(*line, tmp, lentoeol + 1);
	*line[lentoeol] = '\0';
	free(keep);
	remain = ft_strlen(tmp) - (size_t)lentoeol;
	keep = (char*)malloc(sizeof(char) * (remain + 1));
	ft_strncpy(keep, &tmp[lentoeol], remain + 1);
	free(buf);
	free(tmp);
	return (1);
}
