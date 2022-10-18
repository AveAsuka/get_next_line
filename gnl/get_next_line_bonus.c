/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:18:37 by rabderus          #+#    #+#             */
/*   Updated: 2021/12/27 23:23:27 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	exterminate(char **execution)
{
	if (*execution && execution)
	{
		free (*execution);
		*execution = NULL;
	}
}

char	*move_buf(char *buffer, int check)
{
	char	*a;
	int		i;

	if (check >= 0)
	{
		i = ft_strlen(buffer) - check;
		a = buffer;
		check++;
		buffer = (char *) malloc((i + 1) * sizeof(char));
		i = 0;
		while (a[check])
		{
			buffer[i++] = a[check];
			check++;
		}
		buffer[i] = '\0';
		exterminate(&a);
	}
	else
	{
		exterminate(&buffer);
		buffer = (char *)malloc(1);
		buffer[0] = '\0';
	}
	return (buffer);
}

char	*buffer_is_there(char *buffer, char *result, int *check)
{
	char	*tmp;

	*check = ft_index(buffer, '\n');
	tmp = result;
	result = ft_strjoin(result, buffer, *check);
	exterminate(&tmp);
	return (result);
}

char	*get_next_line_two(int *check, char **buffer, int fd, char *result)
{
	int		i_read;
	int		i;
	char	*new;

	i_read = 1;
	i = 0;
	exterminate(buffer);
	new = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (i_read > 0 && *check < 0)
	{
		i_read = read(fd, new, BUFFER_SIZE);
		if (i_read == -1 || (i == 0 && i_read == 0 && ft_strlen(result) == 0))
		{
			exterminate(&new);
			exterminate(&result);
			return (NULL);
		}
		new[i_read] = '\0';
		i++;
		if (new)
			result = buffer_is_there(new, result, check);
	}
	*buffer = new;
	return (result);
}

char	*get_next_line(int fd)
{
	static char		*buffer[10243];
	char			*result;
	int				check;

	result = NULL;
	check = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[fd])
		result = buffer_is_there(buffer[fd], result, &check);
	if (check < 0)
		result = get_next_line_two(&check, &buffer[fd], fd, result);
	if (result == NULL)
		return (NULL);
	buffer[fd] = move_buf(buffer[fd], check);
	if (buffer[fd][0] == '\0')
		exterminate(&buffer[fd]);
	return (result);
}
