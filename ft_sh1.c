/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:18:14 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/26 15:12:06 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	**g_env;

void	prompt(void)
{
	char	*get_pwd;
	char	*tmp;

	get_pwd = NULL;
	get_pwd = getcwd(get_pwd, 0);
	ft_putstr(C_MAGENTA);
	ft_putstr(find_env("USER"));
	ft_putstr(C_NONE);
	ft_putstr(" in ");
	ft_putstr(C_CYAN);
	if (ft_strstr(get_pwd, find_env("HOME")))
	{
		tmp = get_pwd;
		get_pwd = ft_strdup(ft_strstr(get_pwd, find_env("HOME")) +
			ft_strlen(find_env("HOME")));
		free(tmp);
		ft_putstr("~");
	}
	ft_putstr(get_pwd);
	free(get_pwd);
	ft_putstr(" > ");
	ft_putstr(C_NONE);
}

int		ft_exeve(char **all_path, char **ptr2, int i)
{
	char	*cmd;
	pid_t	father;

	while (i != 1 && all_path != NULL)
	{
		cmd = make_joint_of_cmd(all_path, ptr2, i);
		if (access(cmd, X_OK) != -1)
		{
			father = fork();
			if (father > 0)
				wait(NULL);
			if (father == 0)
			{
				execve(cmd, ptr2, g_env);
				exit(EXIT_FAILURE);
			}
			free(cmd);
			return (1);
		}
		free(cmd);
		i--;
	}
	return (0);
}

void	run_shell(char **ptr2, char **all_path, int i)
{
	pid_t	father;

	if (access(ptr2[0], X_OK) != -1)
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		if (father == 0)
		{
			execve(ptr2[0], ptr2, g_env);
			ft_putstr_fd("ft_sh1: exec format error: ", 2);
			ft_putendl_fd(ptr2[0], 2);
			exit(EXIT_FAILURE);
		}
	}
	else if (ft_exeve(all_path, ptr2, i) == 0)
	{
		ft_putstr_fd("ft_sh1: Command not found : ", 2);
		ft_putendl_fd(ptr2[0], 2);
	}
	return ;
}

char	*unspace_it(char *ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		if (ft_is_space(ptr[i]) == 1)
			ptr[i] = ' ';
		i++;
	}
	return (ptr);
}

int		main(int argc, char **argv, char **env)
{
	char	*ptr;
	char	**ptr2;
	int		nb_arg;
	char	**all_path;
	int		i;

	ft_dup_env(env, argc, argv);
	while (1)
	{
		prompt();
		if (get_next_line(0, &ptr) == -1)
		{
			ft_putendl_fd("Error GNL", 2);
			exit(EXIT_FAILURE);
		}
		ptr = unspace_it(ptr);
		ptr2 = ft_strsizesplit(ptr, ' ', &nb_arg);
		free(ptr);
		all_path = ft_strsizesplit(find_env("PATH"), ':', &i);
		if (nb_arg != 0 && built_in(ptr2, nb_arg) == 0)
			run_shell(ptr2, all_path, i);
		ft_free_me(nb_arg, ptr2, all_path);
	}
	free_g_env();
	return (0);
}
