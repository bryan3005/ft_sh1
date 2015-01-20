/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 09:45:58 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/19 13:53:47 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	run_env2(char **var)
{
	int i;

	i = 0;
	while (var[i]!= NULL)
	{
		ft_putendl(var[i]);
		i++;
	}
}

char	**ft_restralloc2_no_free(char **map, int length, int find_place)
{
	char	**tmp;
	int		i;

	ft_putnbr(length);
	i = -1;
	tmp = map;
	map = (char **)malloc((length + 1) * sizeof(char*));
	if (map == NULL)
		return (NULL);
	map[length] = NULL;
	while (++i < find_place)
			map[i] = tmp[i];
	// i++;
	while (i < length)
	{
			map[i] = tmp[i + 1];
			i++;
	}
	return (map);
}

t_env		run_unsetenv(char *name, int overwrite, t_env var)
{
	int find_place;
	find_place = check_is_present(name, var);
	ft_putnbr(find_place);
	if (find_place == -1 || overwrite <= 0)
		return (var);
	var.env = ft_restralloc2_no_free(var.env, var.size_env, find_place);
	return (var);
}