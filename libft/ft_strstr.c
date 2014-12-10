/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:42:59 by amulin            #+#    #+#             */
/*   Updated: 2014/12/05 19:32:39 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void my_varincrement(int *i, int *j)
{
	*i = *i + 1;
	*j = *j + 1;
}

char		*ft_strstr(const char *hay, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (hay == NULL || needle == NULL)
		return (NULL);
	if (needle[j] == '\0')
		return ((char*)&hay[0]);
	while (hay[i] != '\0')
	{
		if (hay[i] == needle[j])
			my_varincrement(&i, &j);
		else if (needle[j] == '\0')
			return ((char*)&hay[i - j]);
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (hay[i] == '\0' && needle[j] == '\0')
		return ((char*)&hay[i - j]);
	return (NULL);
}
