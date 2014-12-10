/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 12:28:07 by amulin            #+#    #+#             */
/*   Updated: 2014/12/05 17:57:48 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_strrev(char *s)
{
	size_t	i;
	size_t	len;
	char	buf;

	i = 0;
	if (ft_strlen(s) > 0)
	{
		len = ft_strlen(s) - 1;
		while (i <= len / 2)
		{
			buf = s[i];
			s[i] = s[len - i];
			s[len - i] = buf;
			i++;
		}
	}
}

static void	my_blankremove(char *s)
{
	size_t	i;
	size_t	j;
	char	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == 32 || s[i] == '\t' || s[i] == '\n') && flag == 0)
			i++;
		else
		{
			s[j] = s[i];
			flag = 1;
			i++;
			j++;
		}
	}
	s[j] = '\0';
}

char		*ft_strtrim(char const *s)
{
	char	*buf;

	if (s == NULL)
		return (NULL);
	buf = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (buf == NULL)
		return (NULL);
	ft_strcpy(buf, s);
	my_blankremove(buf);
	my_strrev(buf);
	my_blankremove(buf);
	my_strrev(buf);
	return (buf);
}
