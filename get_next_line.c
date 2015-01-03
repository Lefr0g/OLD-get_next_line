/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:09:04 by amulin            #+#    #+#             */
/*   Updated: 2014/12/17 19:20:34 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*my_extend(char **dst, char **src)
{
	char	*buf;

	buf = (char*)malloc(sizeof(char) * (ft_strlen(*dst) + 1));
	ft_strcpy(buf, *dst);
	printf(">> my_extend : about to free(*dst) at %p\n", *dst);
	free(*dst);
	*dst = (char*)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(*src) + 1));
	ft_strcpy(*dst, buf);
	*dst = ft_strcat(*dst, *src);
	printf(">> my_extend : about to free(buf) at %p\n", buf);
	free(buf);
	return (*dst);
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
	char		*lline;
	ssize_t		ret;
	int			flag;
	int			lentoeol;
	int			remain;

	if (fd < 0 || line == NULL)
		return (-1);
	lline = *line;
	free(lline);
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
	printf(">> tmp = %s at %p\n", tmp, tmp);
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	flag = 0;
	while (!flag && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[BUFF_SIZE] = '\0';
		tmp = my_extend(&tmp, &buf);
		ft_bzero(buf, BUFF_SIZE);
		if ((lentoeol = my_check_eol(tmp)) >= 0)
			flag = 1;
		printf(">> lentoeol = %d, tmp = %s\n", lentoeol, tmp);
	}
	if (ret == 0 && !tmp)
		return (0);
	if (lentoeol == -1)
		lentoeol = ft_strlen(tmp);
	lline = (char*)malloc(sizeof(char) * lentoeol);
	if (!line)
		return (-1);
	*line = lline;
//	printf(">> tmp = %s\n", tmp);
	ft_strncpy(lline, tmp, lentoeol);
	lline[lentoeol] = '\0';
	printf(">> keep = %s at %p\n", keep, keep);
	free(keep);
	remain = ft_strlen(tmp) - lentoeol;
	printf(">> ft_strlen(tmp) = %zd, lentoeol = %d, tmp = %s\n", ft_strlen(tmp), lentoeol, tmp);
	keep = (char*)malloc(sizeof(char) * (remain));
	ft_strncpy(keep, &tmp[lentoeol + 1], remain);
/*	printf("\n>> tmp = %s", tmp);
	printf(">> keep = %s\n", keep);
	printf(">> lline = %s\n", lline);
*/	printf(">> buf = %s at %p\n", buf, buf);
	free(buf);
	if (ret == 0 && my_check_eol(tmp) == -1)
		return (0);
	printf(">> tmp = %s at %p\n", tmp, tmp);
	ft_bzero(tmp, ft_strlen(tmp));
	printf(">> tmp = %s at %p\n", tmp, tmp);
	free(tmp);
	return (1);
}
