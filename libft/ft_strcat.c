/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:40:01 by amulin            #+#    #+#             */
/*   Updated: 2014/11/11 13:40:04 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int origin;
	int i;

	i = 0;
	origin = 0;
	while (dest[origin] != '\0')
		origin++;
	while (src[i] != '\0')
	{
		dest[origin + i] = src[i];
		i++;
	}
	dest[origin + i] = '\0';
	return (dest);
}
