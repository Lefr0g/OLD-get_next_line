/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 20:10:47 by amulin            #+#    #+#             */
/*   Updated: 2014/12/04 16:25:29 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	my_varsetzero(size_t *i)
{
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
}

static size_t	my_counter(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		if (s[i] != c)
			flag++;
		i++;
	}
	if (i != 0 && count == 0 && flag != 0)
		count++;
	return (count);
}

static size_t	my_strlenchar(char const *s, char c, size_t *i)
{
	size_t	x;
	size_t	len;

	len = 0;
	x = *i;
	if (s == NULL)
		return (0);
	while (s[x] == c)
		x++;
	while (s[x] != '\0' && s[x] != c)
	{
		len++;
		x++;
	}
	*i = x;
	return (len);
}

static void		my_strfill(char const *s, char **buff, size_t *i)
{
	ft_strncpy(buff[i[3]], &s[i[1] - i[2]], i[2]);
	buff[i[3]][i[2]] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	char	**buff;
	size_t	i[4];

	if (s == NULL)
		return (NULL);
	i[0] = my_counter(s, c);
	buff = (char**)malloc(sizeof(char*) * (i[0] + 1));
	if (buff == NULL)
		return (NULL);
	my_varsetzero(i);
	while (i[3] <= i[0])
	{
		i[2] = my_strlenchar(s, c, &i[1]);
		buff[i[3]] = (char*)malloc(sizeof(char) * (i[2] + 1));
		if (buff[i[3]] == NULL)
			return (NULL);
		if (i[3] == i[0])
			buff[i[3]] = NULL;
		else
			my_strfill(s, buff, i);
		i[3]++;
	}
	return (buff);
}
