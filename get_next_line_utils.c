/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:28:38 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/10 19:43:16 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_enddemoeder(char **save, char **line, int fd)
{
	*line = fill_line(save[fd]);
	free(save[fd]);
	if (!*line)
		return (-1);
	save[fd] = 0;
	return (0);
}

size_t		ft_n(const char *str, int set)
{
	size_t	i;

	if (set == 1)
	{
		i = 0;
		if (str[i] == '\0' && str[i] == '\n')
			return (i);
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		return (i + 1);
	}
	if (set == 2)
	{
		i = 0;
		if (str[i] == '\0')
			return (i);
		while (str[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

static char	*strcathelp(char *dest, char *origin, char *append)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (origin[i] != '\0')
	{
		dest[i] = origin[i];
		i++;
	}
	while (append[x] != '\0')
	{
		dest[i] = append[x];
		i++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strcat(char *origin, char *append)
{
	int		x;
	char	*dest;

	x = ft_n(origin, 2) + ft_n(append, 2);
	dest = (char*)malloc(sizeof(char) * (x + 1));
	if (!dest)
	{
		free(origin);
		free(append);
		return (0);
	}
	dest = strcathelp(dest, origin, append);
	free(origin);
	free(append);
	return (dest);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (ft_n(s, 2) < len)
		substr = malloc(sizeof(char) * (ft_n(s, 2)) + 1);
	else
		substr = malloc(sizeof(char) * (len) + 1);
	if (!substr)
	{
		free(s);
		return (0);
	}
	i = 0;
	while (i < len && s[start])
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	free(s);
	substr[i] = '\0';
	return (substr);
}
