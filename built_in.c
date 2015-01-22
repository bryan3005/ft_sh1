/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 12:12:55 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/22 14:06:59 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

extern char	**g_env;

int 	built_in(char **ptr2, int nb_arg)
{
	if (ft_strequ(ptr2[0],"exit"))
		exit(EXIT_SUCCESS);
	else if (ft_strequ(ptr2[0],"cd"))
	{
		run_cd(ptr2, nb_arg);
		return (1);
	}
	else if (ft_strequ(ptr2[0],"setenv"))
	{
		run_setenv(ptr2[1], ptr2[2], ft_atoi(ptr2[3]));
		return (1);
	}
	else if (ft_strequ(ptr2[0],"env"))
	{
		run_env();
		return (1);
	}
	else if (ft_strequ(ptr2[0],"unsetenv"))
	{
		run_unsetenv(ptr2[1], ft_atoi(ptr2[2]));
		return (1);
	}
	return (0);
}

// void	run_old_path(void)
// {
// 	find_env("OLDPWD");
// 	ch
// }

void 	run_cd(char **ptr2, int nb_arg)
{
	char *path;

	if (nb_arg >= 4)
		ft_putendl_fd("cd: too many arguments", 2);
	else if (nb_arg == 3)
	{
		ft_putstr_fd("cd : string not in pwd: ", 2);
		ft_putendl_fd(ptr2[1], 2);
	}
	else if (nb_arg == 1 || ft_strequ(ptr2[1], "~"))
	{
		path = find_env("HOME");
		chdir(path);
		set_old_path();
	}
	else if (ft_strequ(ptr2[1], "-"))
	{
		chdir(find_env("OLDPWD"));
		set_old_path();
	}
	else
	{
		if (check_if_is_directory(ptr2) == 0)
		{
			ft_putstr_fd("cd : not a directory: ", 2);
			ft_putendl_fd(ptr2[1], 2);
		}
		// faire toute la gestion d'erreur
		else
		{
			chdir(ptr2[1]);
			set_old_path();
		}
	}
}

int 	check_if_is_directory(char **ptr2)
{
	if (opendir(ptr2[1]) == NULL && ptr2[1] != NULL)
		return (0);
	else
		return (1);
}

void	set_old_path(void)
{
	char *run_old_path;

	run_old_path = NULL;
	run_setenv("OLDPWD", find_env("PWD"), 1);
	run_setenv("PWD", getcwd(run_old_path, 0), 1);
	// ft_putstr(run_old_path);
	// chdir(run_old_path);
}