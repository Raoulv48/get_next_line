/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 16:15:21 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/10 19:53:26 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# ifndef MAX_FD
#  define MAX_FD 1024
# endif
# include <unistd.h>
# include <stdlib.h>

int			ft_enddemoeder(char **save, char **line, int fd);
char		*ft_strcat(char *origin, char *append);
char		*fill_line(char *save);
size_t		ft_n(const char *str, int set);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);
#endif
