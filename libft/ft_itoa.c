/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:13:07 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/01/31 19:32:20 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_karg(int n)
{
	int	karg;

	karg = 1;
	while (n >= 10)
	{
		karg++;
		n /= 10;
	}
	return (karg);
}

static void	fill(char *num, int karg, int n, int sign)
{
	num[karg + sign] = '\0';
	while (karg > 0)
	{
		num[karg + sign - 1] = '0' + (n % 10);
		n /= 10;
		karg--;
	}
	if (sign)
		num[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*num;
	int		karg;
	int		sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	karg = get_karg(n);
	num = (char *)malloc(sign + karg + 1);
	if (!num)
		return (NULL);
	fill(num, karg, n, sign);
	return (num);
}
