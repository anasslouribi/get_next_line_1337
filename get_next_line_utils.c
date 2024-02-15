/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouribi <alouribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:47:24 by alouribi          #+#    #+#             */
/*   Updated: 2024/01/18 16:23:52 by alouribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (d == NULL && s == NULL)
		return (d);
	if (s == d)
		return (s);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	s1l;
	size_t	s2l;

	s3 = NULL;
	if (!s2 && !s1)
		return (NULL);
	s2l = ft_strlen(s2);
	s1l = ft_strlen(s1);
	s3 = (char *)malloc(s1l + s2l + 1);
	if (!s3)
		return (free(s1), NULL);
	ft_memcpy(s3, s1, s1l);
	ft_memcpy(s3 + s1l, s2, s2l);
	s3[s1l + s2l] = 0;
	return (free(s1), s3);
}
