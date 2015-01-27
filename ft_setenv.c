/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 15:57:34 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/27 11:31:29 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

extern char	**g_env;

int		lt_to_equ_sign(char *src)
{
	int i;

	i = 0;
	while (src[i] != '=' && src[i])
		i++;
	return (i);
}

int		check_is_present(char *name)
{
	int i;

	i = 0;
	while (g_env[i] != NULL && g_env)
	{
		if (ft_strnequ(g_env[i], name, lt_to_equ_sign(g_env[i])))
			if (ft_strlen(name) == ft_strclen(g_env[i], '='))
				return (i);
		i++;
	}
	return (-1);
}

char	**ft_restralloc_no_free(char **map, int length)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = map;
	map = (char **)malloc((length + 2) * sizeof(char*));
	if (map == NULL)
		return (NULL);
	while (++i != length)
		map[i] = tmp[i];
	map[i] = NULL;
	return (map);
}

int		ft_count_env(void)
{
	int i;

	i = 0;
	while (g_env[i] != NULL && g_env)
		i++;
	return (i);
}

void	run_setenv(char *name, char *value, int overwrite)
{
	int		places_of_name;
	char	*tmp;

	if ((places_of_name = check_is_present(name)) != -1 && overwrite != 0)
	{
		free(g_env[places_of_name]);
		g_env[places_of_name] = ft_strjoin(name, "=");
		tmp = g_env[places_of_name];
		g_env[places_of_name] = ft_strjoin(g_env[places_of_name], value);
		free(tmp);
	}
	else if (overwrite != 0)
	{
		places_of_name = ft_count_env();
		g_env = ft_restralloc_no_free(g_env, places_of_name);
		g_env[places_of_name] = ft_strjoin(name, "=");
		tmp = g_env[places_of_name];
		g_env[places_of_name] = ft_strjoin(g_env[places_of_name], value);
		free(tmp);
	}
	return ;
}
