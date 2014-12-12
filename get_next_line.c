/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:09:04 by amulin            #+#    #+#             */
/*   Updated: 2014/12/11 18:22:13 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	ssize_t		ret;
	char		buf[BUFF_SIZE];
	static char	keep[BUFF_SIZE + 1];
	char		*tmp;
	static int	lineindex = 0;
	int			offset;
	int			flag;

//	Check erreur sur parametres
	if (line == NULL || fd < 0)
		return (-1);
// Initialisation compteur et flag
	flag = 0;
	offset = 0;
//	Confition initialisation keep[] sur premiere passe
	if (lineindex == 0)
		*keep = '\0';
//	Boucle read() principale
	while ((ret = read(fd, buf, BUFF_SIZE)) && !flag)
	{
		if (ret == -1)
//			Erreur
			return (-1);
//		Check si \n dans buf | retenir position
		if (ret > 0)
		{
			while (buf[offset] != '\n' && offset <= BUFF_SIZE)
			{
				offset++;
				if (buf[offset] == '\n')
					flag = 1;
			}
//			Remplacer \n par \0 si \n prealablement detecte
			if (flag)
				buf[offset] = '\0';
//			Concatenation buf[] derriere keep[] dans tmp[]. Buf peut ne pas contenir \n
			tmp = ft_strjoin(keep, buf);
//			Clear de keep[]
			ft_strclr(keep);
//			Copie de tmp[] dans keep[]
			ft_strcpy(keep,tmp);
		}
		if (ret == 0)
//			Lecture terminee
			return (0);
	}
	if (flag)
	{
		line[lineindex] = (char*)malloc(sizeof(char) * offset);
		ft_strcpy(line[lineindex], buf);
		lineindex++;
		ft_strdel(&tmp);
		return (1);
	}
	else
		return (2);
//		For debug only. to be removed.
}
