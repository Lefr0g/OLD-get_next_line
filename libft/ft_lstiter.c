/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:30:03 by amulin            #+#    #+#             */
/*   Updated: 2014/12/08 16:51:54 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*buf;

	buf = lst;
	if (lst != NULL && (*f) != NULL)
	{
		while (buf->next != NULL)
		{
			(*f)(buf);
			buf = buf->next;
		}
		(*f)(buf);
	}
}
