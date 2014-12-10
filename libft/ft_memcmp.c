/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:49:52 by amulin            #+#    #+#             */
/*   Updated: 2014/11/20 18:01:45 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		buf1 = (unsigned char*)s1;
		buf2 = (unsigned char*)s2;
		while (i < n)
		{
			if (buf1[i] != buf2[i])
				return (buf1[i] - buf2[i]);
			i++;
		}
	}
	return (0);
}
