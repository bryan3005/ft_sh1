/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 10:37:52 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/22 16:31:03 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_to_fill(char **line, char **str, char *ptr)
{
	char	*toto;
	int		i;

	i = 0;
	if (*ptr == '\n')
		i = 1;
	*ptr = 0;
	*line = ft_strjoin("", *str);
	toto = *str;
	*str = ft_strjoin(ptr + 1, "");
	free(toto);
	return (i);
}

static int	ft_read(char **str, int fd)
{
	int		i;
	char	buff[BUFF_SIZE + 1];
	char	*ptr;

	i = read(fd, buff, BUFF_SIZE);
	if (i == -1)
		return (-1);
	buff[i] = 0;
	ptr = *str;
	*str = ft_strjoin(*str, buff);
	if (*ptr != 0)
		free(ptr);
	return (i);
}

int			get_next_line(int const fd, char **line)
{
	static char *str;
	int			i;
	char		*ptr;

	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (str == 0)
		str = "";
	i = BUFF_SIZE;
	while (1)
	{
		ptr = str;
		while (*ptr || i < BUFF_SIZE)
		{
			if (*ptr == '\n' || *ptr == 0 || *ptr == -1)
				return (ft_to_fill(line, &str, ptr));
			ptr++;
		}
		i = ft_read(&str, fd);
		if (i == -1)
			return (-1);
	}
}
