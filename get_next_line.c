/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:09:04 by amulin            #+#    #+#             */
/*   Updated: 2014/12/12 16:37:34 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*my_strextend(char *a, char *b)
{
	char	*c;

	c = ft_strjoin(a, b);
	ft_strdel(&a);
	a = c;
	ft_strdel(&c);
	return (a);
}

static size_t	my_strlenendofline(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	ssize_t		ret;
	char		buf[BUFF_SIZE + 1];
	static char	*keep;
	char		*tmp;
	static int	lineindex = 0;
	size_t		i;
	int			flag;

//	Check erreur sur parametres
	if (line == NULL || fd < 0)
		return (-1);
//	Initialisation compteur et flag
	flag = 0;
	i = 0;
	tmp = my_strextend(tmp, keep);
//	Initialisation keep[] sur premiere passe
	if (lineindex == 0)
		*keep = '\0';
//	Boucle read() principale
	while ((ret = read(fd, buf, BUFF_SIZE)) && !flag)
	{
		if (ret == -1)
//			Erreur
			return (-1);
		buf[ret] = '\0';
//		Check si \n dans buf | si oui, lever le flag
		if (ret > 0)
		{
			i = 0;
			while (buf[i] != '\n' && i <= BUFF_SIZE)
			{
				i++;
				if (buf[i] == '\n')
					flag = 1;
			}
//		Sauvegarde du buf dans tmp
		my_strextend(tmp, buf);
		}
		if (ret == 0)
//			Lecture terminee
			return (0);
	}
	if (flag) // ou EOF
	{
		i = 0;
//		Trouver position du premier \n ou \0 dans buf
		i = my_strlenendofline(tmp);
//		Malloc de la chaine finale selon la bonne longueur
		line[lineindex] = (char*)malloc(sizeof(char) * (i + 1));
//		Copie de tmp jusqu'a /n exclus dans la chaine finale
		ft_strncpy(line[lineindex], tmp, i);
//		Fermeture de la chaine finale
		line[lineindex][i] = '\0';
//		Copie du reste dams keep
		keep = ft_strsub(tmp, (unsigned int)i, my_strlen(&tmp[i + 1]));
		lineindex++;
//		Liberation de la memoire de tmp
		ft_strdel(&tmp);
		return (1);
	}
	else
		return (2);
//		For debug only. to be removed.
}
