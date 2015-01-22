/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:44:04 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/22 00:05:49 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s1;
	if (!ptr[0] && !s2[0])
		return (ptr);
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	while (*ptr)
	{
		if (*ptr == s2[0] || s2[0] == '\0')
		{
			i = 0;
			while (*(ptr + i) == s2[i] || s2[0] == '\0')
			{
				if (s2[i + 1] == '\0')
					return (ptr);
				i++;
			}
		}
		ptr++;
	}
	return (NULL);
}
