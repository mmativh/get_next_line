/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:23:46 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/19 15:22:14 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int ft_nl(char const *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		if(s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
static char *ft_strjoinfree(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*temp;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	temp = (char*)malloc(sizeof(char) * (len1 + len2) + 1);
	ft_strcpy(temp, s1);
	ft_strcpy(temp, s2);
	temp[len1 + len2 + 1] = '\0';
	free(s1);
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
	int			i;
	char		buf[BUFF_SIZE + 1];
	static char *sstr;

	if ((fd < 0) || !line)
		return (-1);
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE))) 
	{
		buf[ret] = '\0';
		if(!sstr)
		    sstr = ft_strdup(buf);
		if ((i = ft_nl(sstr)))
		    break;
		sstr = ft_strjoinfree(sstr, buf);
	}
	if ((i = ft_nl(sstr)))
	{
		len = ft_strlen(sstr);
		printf("%s \n",*line = ft_strsub(sstr, 0, i - 1));
		sstr = ft_strsubfree(sstr, i, len);
		return (1);
	}
	else if (sstr && ret != 0)
	{
	    *line = ft_strdup(sstr);
        return (1);
	}
	return (0);
}

int main ()
{
	char *line;
	int fd;

	fd = open("test.txt", O_RDONLY);
	while(get_next_line(fd, &line));
//	char s[11] = "helloooooo";
//	char *r;
//	r = strdup(s);
//	printf("%s",ft_strsubfree(r,0, 3));
	return (0);
}
