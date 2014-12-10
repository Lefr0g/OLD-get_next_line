/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:32:02 by amulin            #+#    #+#             */
/*   Updated: 2014/12/08 18:13:52 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*buf;

	if (alst != NULL && (*del) != NULL)
	{
		buf = *alst;
		(*del)(buf->content, buf->content_size);
		(buf->next) = NULL;
		ft_memdel((void**)alst);
	}
}
