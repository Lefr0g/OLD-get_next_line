/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:35:46 by amulin            #+#    #+#             */
/*   Updated: 2014/12/17 11:50:40 by amulin           ###   ########.fr       */
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
	char	*line;

	line = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!line)
		ft_putstr("Main : malloc line fail.");
	if (argc == 1)
		ft_putstr("Main : Please add a filename\n");
	if (argc == 2)
	{
		ft_putstr("argc = ");
		ft_putnbr(argc);
	}
	if (argc > 2)
	{
		ft_putstr("Main : Too many arguments, only ");
		ft_putstr(argv[1]);
		ft_putstr(" will be considered\n");
	}
	argv = argv;
	ft_putchar('\n');
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Main : open() error. Please check the filename\n");
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
	fd = close(fd);
	if (fd == 0)
		ft_putstr("\nMain : close() success !\n");
	else
		ft_putstr("Main : close() error.\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Main : open() error. Please check the filename\n");
		return (-1);
	}
	else
		ft_putstr("Main : open() success !\n");

	ft_putstr("Main : Tentative de get_next_line sur ce fichier...\n\n");
	ft_putstr("Main : get_next_line 1 return value = ");
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr("\nMain : get_next_line 1 line = ");
	ft_putstr(line);
	ft_putstr("\nMain : get_next_line 2 return value = ");
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr("\nMain : get_next_line 2 line = ");
	ft_putstr(line);
	ft_putstr("\nMain : get_next_line 3 return value = ");
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr("\nMain : get_next_line 3 line = ");
	ft_putstr(line);
	ft_putstr("\n\nMain : end of program\n");
	return(0);
}
