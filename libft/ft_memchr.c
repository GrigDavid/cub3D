/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:59:53 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/01/29 16:39:37 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*p;

	p = (void *)s;
	while (s + n - 1 >= p)
	{
		if (*(unsigned char *)p == (unsigned char)c)
			return (p);
		p++;
	}
	return (0);
}
