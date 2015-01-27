/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:58:43 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/26 14:43:42 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

extern char	**g_env;

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

	if (target == NULL)
		return ;
	ret = check_cd_access(target);
	if (ret == -2)
		ft_putstr_fd("cd: permission denied: ", 2);
	else if (ret == -1)
		ft_putstr_fd("cd: no such file or directory: ", 2);
	else if (chdir(target) == -1)
		ft_putstr_fd("cd: not a directory: ", 2);
	else
		return ;
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
	free(get_pwd);
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
	char *get_pwd;

	get_pwd = NULL;
	run_old_path = NULL;
	get_pwd = getcwd(run_old_path, 0);
	run_setenv("OLDPWD", find_env("PWD"), 1);
	run_setenv("PWD", get_pwd, 1);
	free(run_old_path);
	free(get_pwd);
}
