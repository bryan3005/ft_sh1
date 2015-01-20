/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 15:05:34 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/05 16:39:02 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		content_size = 0;
	}
	if ((new->content = malloc(content_size)) == NULL)
		return (NULL);
	new->content_size = content_size;
	new->next = NULL;
	if (content != NULL)
		ft_memmove(new->content, content, content_size);
	return (new);
}
