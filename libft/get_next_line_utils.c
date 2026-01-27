/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:04:53 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/12 14:36:22 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

int	ft_first(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_cut(char *buff, int first)
{
	char	*res;
	int		i;
	int		len;

	if (!buff || !*buff)
		return (NULL);
	if (buff[first] == '\0')
		return (ft_free(&buff), NULL);
	len = ft_strlen(buff);
	i = first + 1;
	res = (char *)malloc(len - first);
	if (!res)
		return (ft_free(&buff), NULL);
	res[len - first - 1] = '\0';
	while (i < len)
	{
		res[i - first - 1] = buff[i];
		i++;
	}
	ft_free(&buff);
	if (!*res)
		return (ft_free(&res), NULL);
	return (res);
}

char	*ft_join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;	

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (ft_free(&s1), NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (ft_free(&s1), res);
}
