/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:01:46 by maparigi          #+#    #+#             */
/*   Updated: 2023/04/24 19:31:15 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

static char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*cpy;

	if (!s)
		return (NULL);
	cpy = malloc(sizeof(const char) * ft_strlen(s) + 1);
	if (!cpy)
		return (NULL);
	i = -1;
	while (s[++i])
		cpy[i] = ((char *)s)[i];
	cpy[i] = '\0';
	return (cpy);
}

char	*check_access(char **env, char *cmd)
{
	char	**paths;
	char	*str;

	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	paths = ft_split(find_apath(env), ':');
	str = access_path(paths, cmd);
	if (str == NULL)
	{
		free(str);
		ft_free(paths);
		return (NULL);
	}
	ft_free(paths);
	return (str);
}

int	is_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (env[i][0])
			if (ft_strncmp("PATH=", env[i], 5) == 0)
				return (1);
	return (0);
}
