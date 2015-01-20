/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:23:59 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/20 14:57:02 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/wait.h>
# include "libft.h"
# include "get_next_line.h"
# include <dirent.h>
#include <sys/stat.h>

# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[0;34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"

typedef		struct  s_env
{
	char			**env;//
	int				size_env;//
	char			**path;//
	int				nb_path;//
	char			*user;//
	char			*home;//
	int				nb_arg;
}					t_env;


t_env		run_setenv(char *name, char *value, int overwrite, t_env *var);
void	run_env(t_env *var);
int		check_is_present(char *name, t_env var);
t_env		run_unsetenv(char *name, int overwrite, t_env var);

#endif