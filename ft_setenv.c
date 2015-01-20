/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 15:57:34 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/16 20:14:57 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		check_is_present(char *name, t_env var)
{
	int i;

	i = 0;
	while(var.env[i])
	{
		if (ft_strnequ(var.env[i], name, ft_strlen(name)))
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
	map[length + 1] = NULL;
	return (map);
}

t_env 	create_env(char *name, char *value, t_env var)
{
	int i;
	int z;
	char **cpy_plus_one;

	i = 0;
	z = var.size_env;
	ft_putnbr(z);
	ft_putstr("\n");
	cpy_plus_one = (char **)malloc((var.size_env + 2) * sizeof(char*));
	cpy_plus_one[(var.size_env + 1)] = NULL;
	while(z > 0)
	{
		cpy_plus_one[i] = var.env[i];
		i++;
		z--;
	}
	cpy_plus_one[i] = (char *)malloc((ft_strlen(name) + ft_strlen(value) + 1) * sizeof(char));
	cpy_plus_one[i][(ft_strlen(name) + ft_strlen(value))] = '\0';
	cpy_plus_one[i] = ft_strjoin(name, value);
	var.env = cpy_plus_one;
	
	return (var);
}

t_env		run_setenv(char *name, char *value, int overwrite, t_env *var)
{
	int places_of_name;
	(void)overwrite;
	if ((places_of_name = check_is_present(name, *var)) != -1)
	{
		
		if (overwrite != 0)
		{
			var->env[places_of_name] = (char *)malloc((ft_strlen(name) + ft_strlen(value) + 1) * sizeof(char));
			var->env[places_of_name][(ft_strlen(name) + ft_strlen(value) )] = '\0';
			var->env[places_of_name] = ft_strjoin(name, value);
			return(*var);
		}
		if (overwrite == 0)
			return (*var);
		return (*var);
	}
	 else
	{
		ft_putendl("fs");
		var->env = ft_restralloc_no_free(var->env, var->size_env);
		var->env[var->size_env] = (char *)malloc((ft_strlen(name) + ft_strlen(value) + 1) * sizeof(char));
		var->env[var->size_env][(ft_strlen(name) + ft_strlen(value) )] = '\0';
		var->env[var->size_env] = ft_strjoin(name, value);
		// run_env(*var);
		//run_env(var.env);
	 	// name non present donc il faut cree la valeur
	 	// ne marche pas neccessite de faire la copie de env dans 1 tableau de tableau de 1 + grand
	 	return (*var);
	}
	return (*var);
}