/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:23:46 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/22 14:22:53 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
/*
static int ft_nl(char const *s)
{
	int i;

	i = 0;
	while((s[i] != '\0') && (s[i] != '\n'))
		i++;
	return (i);
}
*/
static char *ft_strjoinfree(char *s1, char *s2, int ret)
{
	int		len1;
	int		len2;
	char	*temp;

	len1 = ft_strlen(s1);
	len2 = ret;
	temp = (char*)malloc(sizeof(char) * (len1 + len2) + 1);
	ft_strcpy(temp, s1);
	ft_strcat(temp, s2);
	//free(s1);
	return (temp);
}

static char *ft_strdupfree(char *s)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(s);
	temp = (char *)malloc(sizeof(char) * len + 1);
	while(s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
//	free(s);
	return (temp);
} 

int	get_next_line(const int fd, char **line)
{
	int			ret;
	int			i;
	char		buf[BUFF_SIZE + 1];
	static char *sstr;

	if ((fd < 0) || !line || (ret = read(fd, buf, 0) < 0))
		return (-1);
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE))) 
		i = i + ret;
	printf("%i", i);
	if(!sstr)
	{
		lseek(fd, 0, SEEK_END);
		sstr = (char *)malloc(sizeof(char) * i + 1);
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			sstr = ft_strcat(sstr, buf);
			ft_putstr("tt\n");
		}
	printf("rr=%s", sstr);
	}

	//printf("=%s", sstr);
	if (sstr[0] == '\0')
		return (0);
	i = 0;
	while(sstr[i] != '\0' && sstr[i] != '\n')
		i++;
	*line = ft_strsub(sstr, 0, i);
	sstr = sstr + i + 1;
	return (1);
}
///*
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
	while(get_next_line(p[0], &line))
	{
		printf(">>%s<<\n", line);
	}
	return (0);
} //*/
