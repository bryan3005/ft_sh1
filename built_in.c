/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 12:12:55 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/23 19:04:26 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

extern char	**g_env;

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
		run_setenv(ptr2[1], ptr2[2], ft_atoi(ptr2[3]));
		return (1);
	}
	else if (ft_strequ(ptr2[0], "env"))
	{
		run_env();
		return (1);
	}
	else if (ft_strequ(ptr2[0], "unsetenv"))
	{
		run_unsetenv(ptr2[1], ft_atoi(ptr2[2]));
		return (1);
	}
	return (0);
}

int		check_cd_access(char *bin_path)
{
	char	*path;
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (bin_path[i])
		i++;
	while (bin_path[i] != '/' && i != 0)
		i--;
	path = ft_strndup(bin_path, i);
	if (access(path, F_OK) == -1 && i != 0)
		ret = -1;
	else if (access(path, R_OK) == -1 && i != 0)
		ret = -2;
	else if (access(bin_path, F_OK) == -1)
		ret = -1;
	else if (access(bin_path, R_OK) == -1)
		ret = -2;
	free(path);
	return (ret);
}

void	chdir_me(char *target)
{
	int		ret;

	ret = check_cd_access(target);
	if (ret == -2)
		ft_putstr_fd("cd: permission denied: ", 2);
	else if (ret == -1)
		ft_putstr_fd("cd: no such file or directory: ", 2);
	else if (chdir(target) == -1)
		ft_putstr_fd("cd: not a directory: ", 2);
	else
	{
		free(target);
		return ;
	}
	ft_putendl_fd(target, 2);
}


void	makeprec(void)
{
	char	*get_pwd;
	char	*tmp;

	get_pwd = NULL;
	chdir(find_env("OLDPWD"));
		get_pwd = getcwd(get_pwd, 0);
		if (ft_strstr(get_pwd, find_env("HOME")))
		{
			tmp = get_pwd;
			get_pwd = ft_strdup(ft_strstr(get_pwd, find_env("HOME")) +
				ft_strlen(find_env("HOME")));
			free(tmp);
			ft_putstr("~");
		}
		ft_putendl(get_pwd);
		set_old_path();
}

void	run_cd(char **ptr2, int nb_arg)
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
		makeprec();
	else
	{
		chdir_me(ptr2[1]);
		set_old_path();	
	}
}


int		check_if_is_directory(char **ptr2)
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
}
