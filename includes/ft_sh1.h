/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:23:59 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/22 14:03:30 by mbryan           ###   ########.fr       */
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

int 		built_in(char **ptr2, int nb_arg);
void		run_setenv(char *name, char *value, int overwrite);
void		run_env(void);
int			check_is_present(char *name);
int 		ft_count_env(void);
void		run_unsetenv(char *name, int overwrite);
char		*find_env(char *src);
void		run_env(void);
void		ft_dup_env(char **env, int argc, char **argv);
void		run_cd(char **ptr2, int nb_arg);
int 		check_if_is_directory(char **ptr2);
void		run_old_path(void);
void		set_old_path(void);

#endif