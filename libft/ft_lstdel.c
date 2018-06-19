/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:53:17 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/14 10:01:11 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nodenext;

	while (*alst)
	{
		nodenext = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = nodenext;
	}
	(*alst) = NULL;
}
