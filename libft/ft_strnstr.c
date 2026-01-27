/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:07:21 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/01/30 18:18:05 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (src_len == 0 || dst == src)
		return ((char *)dst);
	while (dst[i] && i + src_len <= n)
	{
		if (!ft_strncmp(dst + i, src, src_len))
			return ((char *)dst + i);
		i++;
	}
	return (0);
}
