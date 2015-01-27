/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 12:12:55 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/27 12:14:33 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

extern char	**g_env;

void	make_setenv(char **ptr2, int nb_arg)
{
	if (nb_arg != 4)
		ft_putendl_fd("setenv: not the right number of arguments\n\
usage : [name] [value] [overwrite]  ", 2);
	else
		run_setenv(ptr2[1], ptr2[2], ft_atoi(ptr2[3]));
}

void	make_unsetenv(char **ptr2, int nb_arg)
{
	if (nb_arg != 3)
		ft_putendl_fd("unsetenv: not the right number of arguments\n\
usage : [name] [overwrite]  ", 2);
	else
		run_unsetenv(ptr2[1], ft_atoi(ptr2[2]));
}

int		built_in(char **ptr2, int nb_arg)
{
	if (ft_strequ(ptr2[0], "exit"))
		exit(EXIT_SUCCESS);
	else if (ft_strequ(ptr2[0], "cd"))
	{
		run_cd(ptr2, nb_arg);
		return (1);
	}
	else if (ft_strequ(ptr2[0], "setenv"))
	{
		make_setenv(ptr2, nb_arg);
		return (1);
	}
	else if (ft_strequ(ptr2[0], "env"))
	{
		run_env();
		return (1);
	}
	else if (ft_strequ(ptr2[0], "unsetenv"))
	{
		make_unsetenv(ptr2, nb_arg);
		return (1);
	}
	return (0);
}

void	make_home(char **ptr2)
{
	char *pwd;

	pwd = ft_strjoin(find_env("HOME"), ptr2[1] + 1);
	chdir_me(pwd);
	set_old_path();
	free(pwd);
}

void	run_cd(char **ptr2, int nb_arg)
{
	if (nb_arg >= 4)
		ft_putendl_fd("cd: too many arguments", 2);
	else if (nb_arg == 3)
	{
		ft_putstr_fd("cd : string not in pwd: ", 2);
		ft_putendl_fd(ptr2[1], 2);
	}
	else if (nb_arg == 1 || ft_strequ(ptr2[1], "~") || ft_strequ(ptr2[1], "--"))
	{
		chdir_me(find_env("HOME"));
		set_old_path();
	}
	else if (ft_strequ(ptr2[1], "-"))
		makeprec();
	else if (ft_strnequ(ptr2[1], "~", 1))
	{
		make_home(ptr2);
	}
	else
	{
		chdir_me(ptr2[1]);
		set_old_path();
	}
}
