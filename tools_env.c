/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:58:20 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/22 14:34:33 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

extern char	**g_env;

void	ft_dup_env(char **env, int argc, char **argv)
{
	int i;

	(void)argc;
	(void)argv;
	i = 0;
	while (env[i])
		i++;
	g_env = (char**)malloc((i + 1) * sizeof(char*));
	g_env[i] = NULL;
	while (i-- != 0)
		g_env[i] = ft_strdup(env[i]);
	i = ft_atoi(find_env("SHLVL"));
	i++;
	run_setenv("SHLVL", ft_itoa(i), 1);
}

char	*find_env(char *src)
{
	size_t i;
	char	*cmp;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (g_env[i] != NULL && g_env)
	{
		cmp = ft_strcdup(g_env[i], '=');
		if (ft_strequ(src, cmp))
		{
			free (cmp);
			return (g_env[i] + ft_strlen(src) + 1);
		}
		free (cmp);
		i++;
	}
	return (NULL);
}

void	run_env(void)
{
	int i;

	i = 0;
	while (g_env[i])
	{
		ft_putendl(g_env[i]);
		i++;
	}
}