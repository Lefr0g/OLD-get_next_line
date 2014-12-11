/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:35:46 by amulin            #+#    #+#             */
/*   Updated: 2014/12/11 12:32:42 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Main de test, ne pas inclure dans le repertoire de rendu final
*/

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	ssize_t	ret;
	char	mainbuf[BUFF_SIZE + 1];

	if (argc == 1)
		ft_putstr("argc = 1");
	if (argc != 1)
	{
		ft_putstr("argc = ");
		ft_putnbr(argc);
	}
	argv = argv;
	ft_putchar('\n');
	fd = open("fichier0", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Main : open() error\n");
		return (-1);
	}
	else
		ft_putstr("Main : open() success !\n");
	ft_putstr("Main : attempting to read file...\n");
	ret = read(fd, mainbuf, BUFF_SIZE);
	mainbuf[ret] = '\0';
	if (ret == -1)
	{
		ft_putstr("Main : read() error\n");
		return (-1);
	}
	else
	{
		ft_putstr("Main : read() success !\n");
		if (ret > 0)
		{
			ft_putstr("Main : ");
			ft_putnbr(ret);
			ft_putstr(" bytes read.\n");
		}
		else
			ft_putstr("EOF reached.\n");
		ft_putstr("Main : read content is :\n\n");
		ft_putstr(mainbuf);
		ft_putchar('\n');
	}
	ft_putstr("\nMain : end of program\n");
	return(0);
}
