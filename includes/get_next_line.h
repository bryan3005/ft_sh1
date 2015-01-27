/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 22:02:48 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/24 19:00:58 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#define BUFF_SIZE 	  10000
#define MAX_SIZE_BUFFER 8000001

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		get_next_line(int const fd, char **line);

#	endif
