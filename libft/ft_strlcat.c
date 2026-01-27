/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:55:18 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/01/29 14:38:04 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(dst);
	if (dstsize > len)
	{
		ft_strlcpy(dst + len, src, dstsize - len);
		return (len + ft_strlen(src));
	}
	else
		return (dstsize + ft_strlen(src));
}
