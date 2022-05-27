/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:54:59 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/27 19:33:31 by maparigi         ###   ########.fr       */
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
	char	**cmdargs;
	char	*str;
	pid_t	pid1;

	if (argc < 2)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	cmdargs = ft_split(argv[1], 32);
	str = check_access(env, cmdargs[0]);
	if (pid1 == 0)
	{
		if (execve(str, cmdargs, env) == -1)
			perror("execve");
	}
	free(str);
	ft_free(cmdargs);
	waitpid(pid1, NULL, 0);
	return (0);
}
