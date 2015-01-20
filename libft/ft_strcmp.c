/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:17:04 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/09 12:27:00 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int ret;

	i = 0;
	while (*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	ret = (int)*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
	return (ret);
}
