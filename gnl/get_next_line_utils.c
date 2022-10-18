/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:17:34 by rabderus          #+#    #+#             */
/*   Updated: 2021/12/27 23:23:16 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_two(int *j, char *str, int len, char *s1)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[(*j)++] = s1[i];
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2, int d)
{
	char	*str;
	int		i;
	int		j;
	int		len_two;
	int		len;

	j = 0;
	len_two = ft_strlen(s2);
	if (d != -1)
		len_two = d + 1;
	str = (char *)malloc(ft_strlen(s1) + len_two + 1);
	if (!str)
		return (NULL);
	len = ft_strlen(s1);
	str = ft_strjoin_two(&j, str, len, s1);
	i = 0;
	while (i < len_two)
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

int	ft_index(char *str, int d)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == d)
			return (i);
		i++;
	}
	return (-1);
}
