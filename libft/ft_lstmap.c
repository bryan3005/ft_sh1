/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 16:04:10 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/05 16:38:16 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_first_one;
	t_list	*new;
	t_list	*old_one;

	if (!lst || !f)
		return (NULL);
	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new = f(lst);
	new_first_one = new;
	while (lst->next != NULL)
	{
		old_one = new;
		lst = lst->next;
		if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		new = f(lst);
		old_one->next = new;
	}
	return (new_first_one);
}
