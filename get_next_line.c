/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouribi <alouribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:47:21 by alouribi          #+#    #+#             */
/*   Updated: 2024/01/18 17:03:49 by alouribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_search(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '\n')
		return (1);
	while (s[i] != '\n' && s[i] != '\0')
	{
		i++;
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
	}
	return (i);
}

static char	*next_line(char *str)
{
	size_t		i;
	size_t		j;
	char		*new;

	i = 0;
	j = 0;
	new = NULL;
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	while (str[i + j] != '\0')
		i++;
	if (i == 0)
	{
		free(str);
		return (NULL);
	}
	new = malloc(i + 1);
	if (!new)
		return (free(str), NULL);
	ft_memcpy(new, str + (j + 1), i);
	new[i] = '\0';
	free(str);
	return (new);
}

static char	*get_the_line(char *str)
{
	char	*res;
	size_t	i;

	res = NULL;
	if (str[0] == '\0')
		return (NULL);
	i = (ft_search(str) + 1);
	res = malloc(sizeof(char) * i);
	if (!res)
		return (NULL);
	ft_memcpy(res, str, i);
	res[i - 1] = '\0';
	return (res);
}

static char	*read_file(char *str, int fd)
{
	char	*buff;
	int		l;

	l = 1;
	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (free(str), NULL);
	while (l > 0)
	{
		l = read(fd, buff, BUFFER_SIZE);
		if (l == -1)
			return (free(str), free(buff), NULL);
		buff[l] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (free(buff), free(str), NULL);
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*res;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	str = read_file(str, fd);
	if (!str)
		return (NULL);
	res = get_the_line(str);
	str = next_line(str);
	return (res);
}
