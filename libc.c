/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:55:12 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/14 13:13:13 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2 && s1)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	newstring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	while (s1[++i] != '\0')
		newstring[i] = s1[i];
	while (s2[j] != '\0')
		newstring[i++] = s2[j++];
	newstring[i] = '\0';
	free(s1);
	return (newstring);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	s = malloc(count * size);
	if (!s)
		return (0);
	while (i < count * size)
	{
		s[i] = '\0';
		i++;
	}
	return ((void *)s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
