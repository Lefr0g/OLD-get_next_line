/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 12:27:27 by amulin            #+#    #+#             */
/*   Updated: 2014/12/04 15:26:53 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens[2];
	size_t	i;
	char	*buf;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens[0] = ft_strlen(s1);
	lens[1] = ft_strlen(s2);
	i = 0;
	buf = (char*)malloc(sizeof(char) * (lens[0] + lens[1] + 1));
	if (buf == NULL)
		return (NULL);
	while (i < lens[0])
	{
		buf[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens[1])
	{
		buf[lens[0] + i] = s2[i];
		i++;
	}
	buf[lens[0] + i] = '\0';
	return (buf);
}
