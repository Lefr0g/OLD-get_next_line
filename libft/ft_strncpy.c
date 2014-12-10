/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:37:47 by amulin            #+#    #+#             */
/*   Updated: 2014/11/20 17:18:39 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t lensrc;
	size_t i;

	if (dst != NULL && src != NULL)
	{
		lensrc = ft_strlen(src);
		i = 0;
		while (i < lensrc && i < n)
		{
			dst[i] = src[i];
			i++;
		}
		if (lensrc < n)
		{
			while (i < n)
			{
				dst[i] = '\0';
				i++;
			}
		}
	}
	return (dst);
}
