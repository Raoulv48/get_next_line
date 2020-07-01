/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 16:14:55 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/13 12:15:49 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		checkfilled(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static	char	*ft_read(int fd, char **save)
{
	char	*str;
	ssize_t	nbytes;

	nbytes = 1;
	while (nbytes != 0)
	{
		str = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!str)
		{
			free(save);
			return (NULL);
		}
		nbytes = read(fd, str, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(save[fd]);
			return (NULL);
		}
		str[nbytes] = '\0';
		save[fd] = ft_strcat(save[fd], str);
		if (checkfilled(save[fd]) == 1)
			return (save[fd]);
	}
	return (save[fd]);
}

char			*fill_line(char *save)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_n(save, 1);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free(save);
		return (NULL);
	}
	while (i < len && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static	char	*validcheck(char *save)
{
	save = malloc(sizeof(char) + 1);
	if (save == NULL)
		return (NULL);
	save[0] = '\0';
	return (save);
}

int				get_next_line(int fd, char **line)
{
	static char		*save[MAX_FD];

	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!save[fd])
		save[fd] = validcheck(save[fd]);
	if (save[fd] == NULL)
		return (-1);
	if (checkfilled(save[fd]) == 0)
	{
		save[fd] = ft_read(fd, save);
		if (save[fd] == NULL)
			return (-1);
	}
	if (checkfilled(save[fd]) == 1)
	{
		*line = fill_line(save[fd]);
		if (!line)
			return (-1);
		save[fd] = ft_substr(save[fd], ft_n(save[fd], 1), ft_n(save[fd], 2));
		if (save[fd] == 0)
			return (-1);
		return (1);
	}
	return (ft_enddemoeder(save, line, fd));
}
