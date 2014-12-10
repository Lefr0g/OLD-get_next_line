/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:56:09 by amulin            #+#    #+#             */
/*   Updated: 2014/12/08 18:30:23 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*buf;
	t_list	*next;

	if (alst != NULL && (*del) != NULL)
	{
		buf = *alst;
		next = buf->next;
		while (buf->next != NULL)
		{
			(*del)(buf->content, buf->content_size);
			buf = next;
			next = buf->next;
		}
		ft_lstdelone(&buf, (*del));
		ft_memdel((void**)alst);
	}
}
