/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:18:14 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/20 17:11:42 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

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


void	run_env(t_env *var)
{
	int i;

	i = 0;
	while (var->env[i])
	{
		ft_putendl(var->env[i]);
		i++;
	}
}

char	*find_path_to_home(char **env)
{
	int i;
	char *path_to_home;

	i = 0;
	while (ft_strnequ(env[i],"HOME",4) != 1 && env[i] != NULL)
	 	i++;
	path_to_home = ft_strdup(env[i] + 5);
	if (!env[i])
		return (NULL);
	else
		return (path_to_home);
}

int 	check_if_is_directory(char **ptr2)
{
	if (opendir(ptr2[1]) == NULL && ptr2[1] != NULL)
		return (0);
	else
		return (1);
}

int 	check_if_is_two_file(t_env var)
{
	if (var.nb_arg == 3)
		return (1);
	return (0);
}

int 	check_if_is_more_file(t_env var)
{
	if (var.nb_arg > 3)
		return (1);
	return (0);
}

void	run_old_path(char **env)
{
	int i;
	char *run_old_path;

	i = 0;
	while (ft_strnequ(env[i],"OLDPWD",6) != 1 && env[i] != NULL)
	 	i++;
	run_old_path = ft_strdup(env[i] + 7);
	if (!env[i])
		return ;
	ft_putstr(run_old_path);
	chdir(run_old_path);
}

t_env	set_old_path(t_env var)
{
	char *old_path;

	old_path = NULL;
	var = run_setenv("OLDPWD=", getcwd(old_path, 0), 1, &var);
	return (var);
}

t_env 	run_cd(char **ptr2, t_env var)
{
	(void)ptr2;
	char *path;
	char *path_to_home;

	if (check_if_is_more_file(var) == 1)
	{
		ft_putendl("cd: too many arguments");
		return (var);
	}
	else if (check_if_is_two_file(var) == 1)
	{
		ft_putstr("cd : string not in pwd: ");
		ft_putendl(ptr2[1]);
		return (var);
	}
	 else if (check_if_is_directory(ptr2) == 0 && ptr2[1][0] != '~' && ptr2[1][0] != '-')
	{
		ft_putstr("cd : not a directory: ");
		ft_putendl(ptr2[1]);
		return (var);
	}
	path = (char*)malloc(1000 * sizeof(char));
	if (path == NULL)
	return (var);
	path_to_home = find_path_to_home(var.env);
	//ft_putstr(ptr2[1]);
	if (ft_strequ(ptr2[1],"/"))
		chdir("/");
	else if (ft_strequ(ptr2[1],"-"))
	{
		run_old_path(var.env);
		return (var);
	}
	var = set_old_path(var);
	// ne marche pas si deux fois cd - a la suite
	if (ptr2[1] == NULL || ft_strequ(ptr2[1],"~"))
	{
		path = ft_strdup(path_to_home);
		chdir(path);
	}
	else
	{
		getcwd(path, 1000);
		path = ft_strjoin(path,"/");
		path = ft_strjoin(path,ptr2[1]);
		//ptr2[1] = ft_strdup(path);
		chdir(path);
	}
	free (path);
	return (var);
}

void prompt(t_env var)
{
	char *get_pwd;
	char	*tmp;

	get_pwd = NULL;
	get_pwd = getcwd(get_pwd, 0);
	ft_putstr(C_MAGENTA);
	ft_putstr(var.user);
	ft_putstr(C_NONE);
	ft_putstr(" in ");
	ft_putstr(C_CYAN);
	if (ft_strstr(get_pwd, var.home))
	{
		tmp = get_pwd;
		get_pwd = ft_strdup(ft_strstr(get_pwd, var.home) + ft_strlen(var.home));
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

t_env	get_env_in_var(t_env var, char **env)
{
	var.env = env;
	int i;

	i = 0;
	var.env = env;
	while (env[i] != NULL)
		i++;
	var.size_env = i;
	i = 0;
	while (ft_strnequ(env[i],"HOME",4) != 1 && env[i] != NULL)
	 	i++;
	 if (env[i] != NULL)
		var.home = ft_strdup(env[i] + 5);
	// else
	// 	var.home = NULL;
	i = 0;
	while (ft_strnequ(env[i],"USER",4) != 1 && env[i] != NULL)
		i++;
	 if (env[i] != NULL)
		var.user = ft_strdup(env[i] + 5);
	i = 0;
	while (ft_strnequ(env[i],"PATH",4) != 1 && env[i] != NULL)
		i++;
	ft_putnbr(i);
	if (i < var.size_env)
	{
	var.path = ft_strsplit(env[i] + 5, ':');
	var.nb_path = nb_path(env[i] + 5);
	}
	else
		var.path = NULL;
	return (var);
}

void	print_var(t_env var)
{
	int i = 0 ;
	ft_putendl(var.user);
	ft_putendl(var.home);
	ft_putnbr(var.size_env);
	ft_putstr("\n");
	ft_putnbr(var.nb_path);
	ft_putstr("\n");
	while(var.path[i] != NULL)
	{	
		ft_putendl(var.path[i]);
		i++;
	}
}

size_t		count_arg(char **ptr2)
{
	int i;

	i = 0;
	if (ptr2 == NULL)
		return (0);
	while (ptr2[i] && ptr2[i][0])
		i++;
	return(i);
}

t_env	run_shell(t_env var)
{
	char	*ptr;
	char	**ptr2;
	char	*cmd;
	int 	i;
	pid_t	father;
	// // struct stat	stt;
	var = get_env_in_var(var, var.env);
	i = var.nb_path;
	prompt(var);
	if (get_next_line(0, &ptr) == -1)
		ft_putendl_fd("Error GNL", 2);
	ptr2 = ft_strsizesplit(ptr, ' ',&(var.nb_arg));
	if (var.nb_arg == 0)
		return (var);
	if (ft_strequ(ptr2[0],"exit"))
		exit(EXIT_SUCCESS);
	else if (ft_strequ(ptr2[0],"cd"))
		var = run_cd(ptr2, var);
	else if (ft_strequ(ptr2[0],"setenv"))
	{
		var = run_setenv(ptr2[1], ptr2[2], ft_atoi(ptr2[3]), &var);
		return (var);
	}
	else if (ft_strequ(ptr2[0],"env"))
	{
		run_env(&var);
	}
	else if (ft_strequ(ptr2[0],"unsetenv"))
	{
		var = run_unsetenv(ptr2[1], ft_atoi(ptr2[2]), var);
		return (var);
	}
	else if (ptr2[0] != NULL)
	{
		// father = fork();
		// if (father > 0)
		// 		wait(NULL);
		// 	if (father == 0)
		// {
		while (i != 1 && var.path != NULL)
		{
			cmd = ft_strjoin(var.path[i - 1], "/"); 
			cmd = ft_strjoin(cmd, ptr2[0]);
			// if (lstat(cmd, &stt) == -1)
			//  	return(var); 
			if (access(cmd, X_OK) != -1)
			{
				father = fork();
				if (father > 0)
				wait(NULL);
				if (father == 0)
					execve(cmd, ptr2, var.env);
				return (var);
			}
			free(cmd);
			i--;
		}
		if (access(ptr2[0], X_OK) != -1)
		{
			father = fork();
			if (father > 0)
				wait(NULL);
			if (father == 0)
			{
				execve(ptr2[0], ptr2, var.env); // si n existe pas ne doit pas lancer excve
				return (var);
			}
		}
		else
		{
		ft_putstr_fd("ft_sh1: Command not found : ", 2);
		ft_putendl_fd(ptr2[0], 2);
		}
	// }
	}

	return (var);
}

int main(int argc, char **argv, char **env)
{
	
	t_env	var;

	(void)argc;
	(void)argv;
	var = get_env_in_var(var, env); // Recupere tt la structure et met dans t_env 
	 // print_var(var);
	while (1)
	{
		// Faire le get next line puis verifier si built in sinon faire exeve
		// father = fork();
		// if (father > 0)
		// 	wait(NULL);
		// if (father == 0)
		
			var = run_shell(var);
	}
	return (0);
}