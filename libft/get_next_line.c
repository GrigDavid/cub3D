/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:51:52 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/02/23 15:51:54 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_trim(char *buff, int first, int last)
{
	char	*res;
	int		i;

	i = first;
	if (!buff)
		return (NULL);
	res = (char *)malloc(last + 1 - first + 1);
	if (!res)
		return (NULL);
	res[last + 1 - first] = '\0';
	while (i <= last)
	{
		res[i - first] = buff[i];
		i++;
	}
	return (res);
}

static char	*ft_get_line(int fd, char *buff)
{
	char	*p;
	int		rd;

	p = (char *)malloc(BUFFER_SIZE + 1);
	if (!p)
		return (ft_free(&buff), NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, p, BUFFER_SIZE);
		if (rd < 0)
			return (ft_free(&p), ft_free(&buff), NULL);
		p[rd] = '\0';
		if (rd > 0)
		{
			if (ft_first(p) != BUFFER_SIZE)
				rd = -1;
			buff = ft_join(buff, p);
			if (!buff)
				return (ft_free(&p), NULL);
		}
	}
	ft_free(&p);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buff;
	char		*p;

	if (fd < 0)
		return (NULL);
	buff = ft_get_line(fd, buff);
	if (!buff)
		return (NULL);
	str = NULL;
	p = ft_trim(buff, 0, ft_first(buff));
	str = ft_join(str, p);
	ft_free(&p);
	buff = ft_cut(buff, ft_first(buff));
	if (!str || !*str)
		ft_free(&buff);
	return (str);
}
