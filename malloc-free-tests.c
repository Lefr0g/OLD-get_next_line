/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 16:34:36 by amulin            #+#    #+#             */
/*   Updated: 2014/12/15 17:36:09 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "libft.h" 

int	get_next_line(int const fd, char **line)
{
	static char	*keep = "abcd";
}
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	my_test(void)
{
	static char	*keep;
	char		*tmp;
	char		*squat;
	static int	i = 0;

	printf("Run %d, keep = %s at %p\n", i, keep, keep);
	tmp = (char*)malloc(sizeof(char) * 11);
	strcpy(tmp, "abcdefgh");
	printf("Run %d, tmp = %s at %p\n", i, tmp, tmp);
	free(keep);
	squat = (char*)malloc(sizeof(char) * (strlen(tmp) + 9));
	printf("Run %d, squat = %s at %p\n", i, squat, squat);
	printf("Run %d, keep = %s at %p (after free)\n", i, keep, keep);
	keep = (char*)malloc(sizeof(char) * (strlen(tmp) + 9));
	strcat(keep, tmp);
	printf("Run %d, keep = %s at %p\n\n", i, keep, keep);
	i++;
	free(squat);
}

int		main(void)
{
	my_test();
	my_test();
	my_test();
	return (0);
}
