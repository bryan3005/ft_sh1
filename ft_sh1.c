/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:18:14 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/22 15:56:57 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	**g_env;
// ptr2
// contient tt les argument passe au shell
// ls -l tryme
// ptr2[0] = ls
// ptr2[1] = -l
// ptr3[2] = tryme
//chdir(const char *path);
//getcwd(char *buf, size_t size);

// dans runcd neccesite de faire un open dir puis readdir pour voir les 
//fichier ouvrable par cd et du coup gestion de l erreur

// Gestion erreur cd si 2 arg ou + (mess erreur diff)
// gestion de l erreur si ce n est pas un directory

// 	Attention pour l instant ne fait pas la differance entre n est pas un directory et n est pas un fichier present


// Gestion du cd sans arg aui renvoi au path de la variable d environnement HOME

// Peut etre faut il gere si cd recoit des option car non gere pour l instant




void prompt(void)
{
	char *get_pwd;
	char	*tmp;

	get_pwd = NULL;
	get_pwd = getcwd(get_pwd, 0);
	ft_putstr(C_MAGENTA);
	if (find_env("USER") != NULL)
		ft_putstr(find_env("USER"));
	ft_putstr(C_NONE);
	ft_putstr(" in ");
	ft_putstr(C_CYAN);
	if (ft_strstr(get_pwd, find_env("HOME")))
	{
		tmp = get_pwd;
		get_pwd = ft_strdup(ft_strstr(get_pwd, find_env("HOME")) + ft_strlen(find_env("HOME")));
		free(tmp);
		ft_putstr("~");
	}
	ft_putstr(get_pwd);
	ft_putstr(" > ");
	ft_putstr(C_NONE);
}

int 	nb_path(char *path)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (path[i])
	{
		if(path[i] ==':')
			nb++;
		i++;
	}
	return (nb + 1);
}

int 	ft_exeve(char **all_path, char **ptr2, int i)
{
	char	*cmd;
	char	*tmp;
	pid_t	father;

	while (i != 1 && all_path != NULL)
	{
		cmd = ft_strjoin(all_path[i - 1], "/");
		tmp = cmd;
		cmd = ft_strjoin(cmd, ptr2[0]);
		free (tmp);
		if (access(cmd, X_OK) != -1)
		{
			father = fork();
			if (father > 0)
			wait(NULL);
			if (father == 0)
			{
				execve(cmd, ptr2, g_env);
				
			}
			return 1;
		}
		free(cmd);
		i--;
	}
	return (0);
}

void	run_shell(char **ptr2)
{
	
	int 	i;
	pid_t	father;
	char 	**all_path;

	all_path = ft_strsizesplit(find_env("PATH"), ':', &i);
	if (access(ptr2[0], X_OK) != -1 )
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		if (father == 0)
		{
			if (execve(ptr2[0], ptr2, g_env) == -1)
			{
				ft_putstr_fd("ft_sh1: exec format error: ", 2);
				ft_putendl_fd(ptr2[0], 2);
				exit(EXIT_FAILURE);
			}
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

int main(int argc, char **argv, char **env)
{
	char	*ptr;
	char	**ptr2;
	int 	nb_arg;

	ft_dup_env(env, argc, argv);
	while (1)
	{
		prompt();
		if (get_next_line(0, &ptr) == -1)
			ft_putendl_fd("Error GNL", 2);
		ptr = unspace_it(ptr);
		ptr2 = ft_strsizesplit(ptr, ' ',&nb_arg);
		if (nb_arg != 0 && built_in(ptr2, nb_arg) == 0)
			run_shell(ptr2);
	}
	return (0);
}
