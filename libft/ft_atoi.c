/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:41:33 by amulin            #+#    #+#             */
/*   Updated: 2014/11/22 18:53:29 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_atoi_nondigit(char *negflag, char *started, const char *nptr)
{
	if (nptr[0] == '-')
	{
		if (*started == 0 && ft_isdigit(nptr[1]))
			*negflag = -1;
		else
			return (1);
	}
	if (!ft_isdigit(nptr[1]) && *started == 1)
		return (1);
	if (nptr[0] == '+')
	{
		if (*started == 0)
			*started = 1;
		else if (*started == 1)
			return (1);
	}
	if (nptr[0] == ' ' && *started == 1)
		return (1);
	if (!ft_isascii(nptr[0]) || (ft_isprint(nptr[0]) && !ft_isdigit(nptr[0])
		&& nptr[0] != '-' && nptr[0] != ' ' && nptr[0] != '+'))
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	int		i;
	int		result;
	char	negflag;
	char	started;

	i = 0;
	result = 0;
	negflag = 1;
	started = 0;
	while (nptr[i] != '\0')
	{
		if (ft_isdigit(nptr[i]))
		{
			result = result * 10 + (nptr[i] - '0');
			started = 1;
		}
		else if (ft_atoi_nondigit(&negflag, &started, &nptr[i]))
			break ;
		i++;
	}
	return (negflag * result);
}
