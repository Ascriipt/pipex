/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:54:59 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/15 16:47:13 by maparigi         ###   ########.fr       */
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
	int	pfd[2];
	int	pid1;

	char *str = add_path(find_apath(env), argv[1], '/');
	char *fpath = rpath(str, ':');

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
		if (execve(fpath, argv, env) == -1)
			perror("execve");
	}
	free(fpath);
	free(str);
	waitpid(pid1, NULL, 0);
	return (0);
}
