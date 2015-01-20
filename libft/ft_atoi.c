/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:29:10 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/07 09:46:21 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int make_it3(const char *str)
{
	int i;
	int result;
	int signe;

	i = 0;
	result = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		signe = (str[i] - 44) * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= signe;
	return (result);
}

int	checkit(const char *str, char *cmp)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] == '0')
		i++;
	while (str[i + len] >= '0' && str[i + len] <= '9')
		len++;
	if (len > ft_strlen(cmp))
		return (-1);
	else if (len == ft_strlen(cmp))
		return (ft_strcmp(cmp, str + i));
	return (1);
}

int ft_atoi(const char *str)
{
	int result;
	int i;
	int signe;

	i = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		signe = 44 - str[i];
		i++;
	}
	if (checkit(str + i, "9223372036854775808") <= 0)
		return (signe == 1) ? -1 : 0;
	result = make_it3(str);
	return (result);
}
