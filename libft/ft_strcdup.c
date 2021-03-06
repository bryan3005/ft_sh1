/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:17:31 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/26 13:24:20 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcdup(const char *s, char c)
{
	char	*cpy;

	cpy = ft_strndup(s, ft_strclen(s, c));
	return (cpy);
}
