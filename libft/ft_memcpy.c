/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 13:22:19 by amulin            #+#    #+#             */
/*   Updated: 2014/12/09 15:37:42 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src0;
	unsigned char		*dst0;

	i = 0;
	src0 = src;
	dst0 = dst;
	while (i < n)
	{
		dst0[i] = src0[i];
		i++;
	}
	return (dst);
}
