/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 08:18:31 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/18 09:13:54 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ifspace(int c)
{
	if ((c == ' ') || (c == '\t') || (c == '\v') ||
			(c == '\r') || (c == '\n') || (c == '\f'))
		return (1);
	return (0);
}
