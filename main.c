/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:54:59 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/27 20:16:19 by maparigi         ###   ########.fr       */
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

void	child_proc(char **env, char **cmdargs, char *str, int pfd[2])
{
	if (dup2(pfd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 : child ");
		exit(EXIT_FAILURE);
	}
	close(pfd[0]);
	execve(str, cmdargs, env);
	close(pfd[1]);
}

void	parent_proc(char **env, char **cmdargs, char *str, int pfd[2])
{
	if (dup2(pfd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 : parent ");
		exit(EXIT_FAILURE);
	}
	close(pfd[1]);
	execve(str, cmdargs, env);
	close(pfd[0]);
}

int	main(int argc, char **argv, char **env)
{
	char	**cmdargs;
	char	*str;
	pid_t	pid1;
	int		pfd[2];

	if (argc < 3)
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
		cmdargs = ft_split(argv[1], 32);
		str = check_access(env, cmdargs[0]);
		child_proc(env, cmdargs, str, pfd);
	}
	else
	{
		cmdargs = ft_split(argv[2], 32);
		str = check_access(env, cmdargs[0]);
		waitpid(pid1, NULL, 0);
		parent_proc(env, cmdargs, str, pfd);
	}
	free(str);
	ft_free(cmdargs);
	return (0);
}
