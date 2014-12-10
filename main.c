/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:35:46 by amulin            #+#    #+#             */
/*   Updated: 2014/12/10 17:54:01 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Main de test, ne pas inclure dans le repertoire de rendu final
*/

#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("argc = 1");
	if (argc != 1)
	{
		ft_putstr("argc = ");
		ft_putnbr(argc);
	}
	argv = argv;
	ft_putchar('\n');
	return(0);
}
