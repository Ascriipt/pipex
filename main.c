/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:54:59 by maparigi          #+#    #+#             */
/*   Updated: 2023/01/16 01:29:04 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

static void	command_nfound(char **cmdargs)
{
	if (cmdargs[0])
	{
		write(STDERR_FILENO, "command not found: ", 19);
		write(STDERR_FILENO, cmdargs[0], ft_strlen(cmdargs[0]));
		write(STDERR_FILENO, "\n", 1);
	}
	ft_free(cmdargs);
	exit(EXIT_FAILURE);
}

void	child_proc(char **argv, char **env, char **cmdargs, int pfd[2])
{
	char	*str;
	int		file1;

	str = check_access(env, cmdargs[0]);
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		free(str);
		perror(argv[1]);
	}
	if (str == NULL)
		command_nfound(cmdargs);
	if (dup2(file1, STDIN_FILENO) == -1)
	{
		ft_free(cmdargs);
		exit(EXIT_FAILURE);
	}
	if (dup2(pfd[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(pfd[0]);
	execve(str, cmdargs, env);
	close(pfd[1]);
	free(str);
	close(file1);
}

void	parent_proc(char **argv, char **env, char **cmdargs, int pfd[2])
{
	char	*str;
	int		file2;

	file2 = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	str = check_access(env, cmdargs[0]);
	if (file2 == -1 || str == NULL)
	{
		if (str == NULL)
		{
			write(STDERR_FILENO, "command not found: ", 19);
			write(STDERR_FILENO, cmdargs[0], ft_strlen(cmdargs[0]));
			write(STDERR_FILENO, "\n", 1);
		}
		free(str);
		ft_free(cmdargs);
		exit(EXIT_FAILURE);
	}
	if (dup2(pfd[0], STDIN_FILENO) == -1
		|| dup2(file2, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(pfd[1]);
	execve(str, cmdargs, env);
	close(pfd[0]);
	free(str);
	close(file2);
}

static void	ft_procs(char **argv, char **env, int *pfd, int pid1)
{
	char	**cmdargs;

	pid1 = fork();
	if (pid1 < 0)
		exit(EXIT_FAILURE);
	if (pid1 == 0)
	{
		cmdargs = ft_split(argv[2], 32);
		if (!cmdargs[0])
			command_nfound(cmdargs);
		child_proc(argv, env, cmdargs, pfd);
	}
	else
	{
		cmdargs = ft_split(argv[3], 32);
		if (!cmdargs[0])
			command_nfound(cmdargs);
		waitpid(pid1, NULL, WNOHANG);
		parent_proc(argv, env, cmdargs, pfd);
	}
	ft_free(cmdargs);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid1;
	int		pfd[2];

	if (argc < 5 || !env || !env[0])
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
