/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:59:57 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/24 16:55:02 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*access_path(char **paths, char *cmd)
{
	char	*apath;
	int		i;

	i = -1;
	while (paths[++i])
	{
		apath = add_path(paths[i], cmd, '/');
		if (access(apath, F_OK) == 0)
			return (apath);
		free(apath);
	}
	return (NULL);
}

char	*add_path(char *str, char *av1, char c)
{
	char	*dst;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (str)
	{
		dst = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(av1) + 2));
		if (!dst)
			return (NULL);
		while (str[++i])
			dst[i] = str[i];
		dst[i++] = c;
		while (av1[++j])
			dst[i++] = av1[j];
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	ma;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	ma = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * ma);
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i++] = s2[j];
	dest[i] = '\0';
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
