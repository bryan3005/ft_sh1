/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 09:45:58 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/27 11:32:14 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

extern char	**g_env;

char	**ft_restralloc2_no_free(char **map, int length, int find_place)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = map;
	map = (char **)malloc((length + 1) * sizeof(char*));
	if (map == NULL)
		return (NULL);
	while (++i < find_place)
		map[i] = ft_strdup(tmp[i]);
	while (i < length - 1 && tmp[i] != NULL)
	{
		map[i] = ft_strdup(tmp[i + 1]);
		i++;
	}
	map[i] = NULL;
	ft_freetabs(tmp);
	return (map);
}

void	run_unsetenv(char *name, int overwrite)
{
	int find_place;

	find_place = check_is_present(name);
	if (find_place == -1 || overwrite <= 0)
		return ;
	g_env = ft_restralloc2_no_free(g_env, ft_count_env(), find_place);
	return ;
}
