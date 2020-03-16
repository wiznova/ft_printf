/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 13:23:22 by skhalil        #+#    #+#                */
/*   Updated: 2020/02/08 18:28:12 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int		empty_before_newline(char **r_buf);
int		read_to_rbuf_til_newline(int fd, char **r_buf);
int		read_from_buf(char **line, char *r_buf, int islast);
int		read_routine(char **line, char **r_buf, int islast);
int		get_next_line(int fd, char **line);
int		ft_strnjoin(char **s1, char *s2, int stopper);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		newline_index(char *str);
int		free_buf(char **r_buf, int ret);

#endif
