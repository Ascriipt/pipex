/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:54:59 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/31 17:50:13 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

void	child_proc(char **env, char **cmdargs, int pfd[2])
{
	char	*str;

	str = check_access(env, cmdargs[0]);
	if (dup2(pfd[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(pfd[0]);
	execve(str, cmdargs, env);
	close(pfd[1]);
	free(str);
}

void	parent_proc(char **env, char **cmdargs, int pfd[2])
{
	char	*str;

	str = check_access(env, cmdargs[0]);
	if (dup2(pfd[0], STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(pfd[1]);
	execve(str, cmdargs, env);
	close(pfd[0]);
	free(str);
}

static void	ft_procs(char **argv, char **env, int *pfd, int pid1)
{
	char	**cmdargs;

	pid1 = fork();
	if (pid1 < 0)
		exit(EXIT_FAILURE);
	if (pid1 == 0)
	{
		cmdargs = ft_split(argv[1], 32);
		if (!cmdargs[0])
			exit(EXIT_FAILURE);
		child_proc(env, cmdargs, pfd);
	}
	else
	{
		cmdargs = ft_split(argv[2], 32);
		if (!cmdargs[0])
			exit(EXIT_FAILURE);
		waitpid(pid1, NULL, 0);
		parent_proc(env, cmdargs, pfd);
	}
	ft_free(cmdargs);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid1;
	int		pfd[2];

	if (argc < 3)
		return (1);
	if (pipe(pfd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = 0;
	ft_procs(argv, env, pfd, pid1);
	return (0);
}
