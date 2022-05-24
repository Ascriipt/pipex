/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:54:59 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/24 16:59:40 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

char	*find_apath(char **env)
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
	char	**paths;
	char	*str;
	int		pfd[2];
	int		pid1;

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
	paths = ft_split(find_apath(env), ':');
	if (access_path(paths, argv[1]) == NULL)
	{
		ft_free(paths);
		perror("access");
		exit(EXIT_FAILURE);
	}
	str = access_path(paths, argv[1]);
	if (pid1 == 0)
	{
		if (execve(str, argv + 1, env) == -1)
			perror("execve");
	}
	ft_free(paths);
	free(str);
	waitpid(pid1, NULL, 0);
	return (0);
}
