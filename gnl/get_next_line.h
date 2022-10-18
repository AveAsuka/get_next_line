/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:19:11 by rabderus          #+#    #+#             */
/*   Updated: 2021/12/27 23:27:24 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_next_line_two(int *check, char **buffer, int fd, char *result);
char	*buffer_is_there(char *buffer, char *result, int *check);
char	*move_buf(char *buffer, int check);
void	exterminate(char **execution);
int		ft_index(char *str, int d);
char	*ft_strjoin(char *s1, char *s2, int d);
char	*ft_strjoin_two(int *j, char *str, int len, char *s1);
int		ft_strlen(char *str);

#endif
