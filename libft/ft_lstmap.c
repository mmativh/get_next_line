/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:48:19 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/14 09:40:39 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nextt;
	t_list *cur;
	t_list *head;

	head = f(lst);
	cur = f(lst);
	head->next = cur;
	while (lst)
	{
		nextt = f(lst);
		cur->next = nextt;
		lst = lst->next;
	}
	return (head);
}
