/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:26:34 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/01/30 17:29:47 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	if (dstsize >= 1 && src)
	{
		if (ft_strlen(src) < dstsize)
		{
			ft_memmove(dst, src, ft_strlen(src));
			dst[ft_strlen(src)] = '\0';
		}
		else
		{
			ft_memmove(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (ft_strlen(src));
}
