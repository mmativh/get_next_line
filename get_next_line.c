/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:23:46 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/23 08:31:13 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

static int ft_nl(char const *s)
{
	int i;

	i = 0;
	while((s[i] != '\0') && (s[i] != '\n'))
		i++;
	return (i);
}

static char *ft_strjoinfree(char *s1, char *s2, int ret)
{
	char	*temp;
	char	len;

	ret = ft_strlen(s1) + ret;
	temp = (char*)malloc(sizeof(char) * ret + 1);
	ft_strcpy(temp, s1);
	ft_strcat(temp, s2);
	return (temp);
}

static char *ft_strsubfree(char *s, int start, int len)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * len + 1);
	while(len)
	{
		temp[i] = s[i + start]; 
		i++;
		len--;
	}
	temp[i] = '\0';
	free(s);
	return (temp);
} 
int	get_next_line(const int fd, char **line)
{
	int			ret;
	int			len;
	char		buf[BUFF_SIZE + 1];
	static char *sstr;

	if ((fd < 0) || !line || (ret = read(fd, buf, 0) < 0))
		return (-1);
	if (!sstr)
		sstr = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE))) 
	{
		buf[ret] = '\0';
		sstr = ft_strjoinfree(sstr, buf, ret);
		if (ft_strchr(buf, '\n'))
		    break;
	}
	if (!(len = ft_strlen(sstr)))
		return (0);
	ret = ft_nl(sstr);
	*line = ft_strsub(sstr, 0, ret);
	sstr = ft_strsub(sstr, ret + 1 , len);
	return (1);
}
/*
int main ()
{
	char *line;
	int fd;
	int		out;
	int		p[2];

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);
	//fd = open("test.txt", O_RDONLY);
	if(get_next_line(p[0], &line))
	{
		printf(">>%i<<\n", strcmp(line, "abc")) ;
	}
	return (0);
} */
