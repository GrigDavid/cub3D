/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:44:47 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/01/29 15:19:17 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*p;

	len = ft_strlen(s);
	p = (unsigned char *)s;
	while ((unsigned char *)s + len >= p)
	{
		if (*p == (unsigned char)c)
			return ((char *)p);
		p++;
	}
	return (0);
}
