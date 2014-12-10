/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:16:47 by amulin            #+#    #+#             */
/*   Updated: 2014/11/20 17:56:35 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (s != NULL)
	{
		i = 0;
		tmp = (unsigned char*)s;
		while (i < n)
		{
			if (tmp[i] == (unsigned char)c)
				return (&tmp[i]);
			i++;
		}
	}
	return (NULL);
}
