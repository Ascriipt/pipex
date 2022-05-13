/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:54:59 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/14 00:08:19 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

static	char	*find_apath(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=/", 6) == 0)
			return (env[i] + 5);
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	int	pfd[2];
	int	pid1;

	if (argc < 0)
		return (1);
	if (pipe(pfd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		if (execve("/usr/bin/ls", argv + 1, env) == -1)
			perror("execve");
	}
	printf("PATH=%s\n", find_apath(env));
	waitpid(pid1, NULL, 0);
	return (0);
}
