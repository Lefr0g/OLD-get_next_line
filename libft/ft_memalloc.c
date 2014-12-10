/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 10:38:23 by amulin            #+#    #+#             */
/*   Updated: 2014/11/28 18:19:36 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (size <= 0)
		return (NULL);
	s = malloc(sizeof(*s) * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
