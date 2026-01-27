/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:19:39 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/01/30 19:35:14 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;

	arr = (char *)malloc(ft_strlen(s1) + 1);
	if (!arr)
		return (0);
	ft_strlcpy(arr, (char *)s1, ft_strlen(s1) + 1);
	return (arr);
}
