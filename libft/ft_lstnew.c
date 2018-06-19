/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:28:46 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/14 09:36:09 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newnode;

	if (!(newnode = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(newnode->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(newnode->content, content, content_size);
		newnode->content_size = content_size;
	}
	else
	{
		newnode->content = NULL;
		newnode->content_size = 0;
	}
	newnode->next = NULL;
	if (newnode == NULL)
		return (NULL);
	return (newnode);
}
