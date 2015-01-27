/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 12:33:22 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/26 12:36:02 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

extern char	**g_env;

void	ft_free_me(int nb_arg, char **ptr2, char **all_path)
{
	if (nb_arg != 0)
		ft_freetabs(ptr2);
	if (all_path != NULL)
		ft_freetabs(all_path);
}

char	*make_joint_of_cmd(char **all_path, char **ptr2, int i)
{
	char	*cmd;
	char	*tmp;

	cmd = ft_strjoin(all_path[i - 1], "/");
	tmp = cmd;
	cmd = ft_strjoin(cmd, ptr2[0]);
	free (tmp);
	return (cmd);
}
