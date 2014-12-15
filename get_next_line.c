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

void	my_extend(char *dest, char *src)
{
	char	*buf;

	buf = (char*)malloc(sizeof(char) * (ft_strlen(dest) + 1));
	ft_strcpy(buf, dest);
	free(dest);
	dest = (char*)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(src) + 1));
	ft_strcpy(dest, buf);
	ft_strcat(dest, src);
	free(buf);
}

int	get_next_line(int const fd, char **line)
{
	static char	*keep;
	char		*tmp;
	char		*buf;
	size_t		ret;
	int			flag;
	
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
		buf(BUFF_SIZE) = '\0';
		my_extend(tmp, buf);
	}
}
