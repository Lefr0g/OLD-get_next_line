/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:42:48 by amulin            #+#    #+#             */
/*   Updated: 2014/12/05 19:25:02 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) > n)
		return (NULL);
	if (needle[j] == '\0')
		return ((char*)&hay[i - j]);
	while (hay[i] != '\0' && i != n)
	{
		if (needle[j] == hay[i])
			j++;
		i++;
		if (needle[j] == '\0')
			return ((char*)&hay[i - j]);
	}
	return (NULL);
}
