/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:07:25 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/22 16:31:56 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		i;
	int		test;
	char	*str;

	test = 0;
	i = ft_intlen(n);
	if ((str = (char *)malloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	str[i] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		test = 1;
		str[0] = '-';
		n *= -1;
	}
	while (i-- > test)
	{
		str[i] = '0' + n % 10;
		n = n / 10;
	}
	return (str);
}
