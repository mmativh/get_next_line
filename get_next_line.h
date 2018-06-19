/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:36:06 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/12 09:37:31 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXT_GEN_LINE_H
# define NEXT_GEN_LINE_H
# include "libft/libft.h"
#define BUFF_SIZE 32

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_next_line(const int fd, char **line);
#endif
