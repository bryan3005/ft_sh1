/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetabs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 19:45:21 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/26 12:41:20 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_freetabs(char **ptr)
{
	int i;

	i = 0;
	if (ptr == NULL)
		return ;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
