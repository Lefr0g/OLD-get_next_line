/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:36:49 by amulin            #+#    #+#             */
/*   Updated: 2014/12/10 12:01:29 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*fresh;
	t_list	*freshinit;

	if (lst != NULL && (*f) != NULL)
	{
		buf = lst;
		fresh = ft_lstnew(NULL, 0);
		freshinit = fresh;
		while (buf != NULL)
		{
			ft_memcpy(fresh, (*f)(buf), sizeof(t_list));
			if (buf->next != NULL)
				fresh->next = ft_lstnew(NULL, 0);
			fresh = fresh->next;
			buf = buf->next;
		}
	}
	return (freshinit);
}
