/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 13:54:56 by amulin            #+#    #+#             */
/*   Updated: 2014/11/20 17:53:40 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src0;
	unsigned char		*dst0;
	unsigned char		c0;

	i = 0;
	src0 = src;
	dst0 = dst;
	c0 = c;
	while (i < n)
	{
		dst0[i] = src0[i];
		if (src0[i] == c0)
		{
			return (&dst0[i + 1]);
		}
		i++;
	}
	return (NULL);
}
