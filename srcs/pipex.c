/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:41:02 by tpriyang          #+#    #+#             */
/*   Updated: 2023/08/27 17:42:25 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	openfiles(char *infile, char *outfile, int *infile_fd, int *outfile_fd)
{
	int	file_permissions;
	int	exit_status;

	exit_status = -1;
	file_permissions = 0666;
	*infile_fd = open(infile, O_RDONLY);
	if (*infile_fd == -1)
		exit_status = 1;
	*outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, file_permissions);
	if (*outfile_fd == -1)
		exit_status = 2;
	if (exit_status == 1)
	{
		perror("command not found, no input file");
		exit(EXIT_FAILURE);
	}
	else if (exit_status == 2)
	{
		perror("command not found, no output file");
		exit(EXIT_FAILURE);
	}
}

pid_t	childpr1(char *argv[], char *envp[], int pipe_fd[], int infile_fd)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork failure child1");
		_exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		dup2(infile_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		command(argv[2], envp);
		exit(EXIT_SUCCESS);
	}
	return (pid1);
}

pid_t	childpr2(char *argv[], char *envp[], int pipe_fd[], int outfile_fd)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork failure child2");
		_exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(pipe_fd[0]);
		command(argv[3], envp);
		exit(EXIT_SUCCESS);
	}
	return (pid2);
}

void	closefunction(int pipe_fd[], int infile_fd, int outfile_fd)
{	
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile_fd);
	close(outfile_fd);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
	pid_t	cpid1;
	pid_t	cpid2;

	infile_fd = -1;
	outfile_fd = -1;
	if (argc != 5)
	{
		perror("command not found ,argc !=5");
		exit(EXIT_FAILURE);
	}
	openfiles(argv[1], argv[4], &infile_fd, &outfile_fd);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe creation failure");
		exit(EXIT_FAILURE);
	}
	cpid1 = childpr1(argv, envp, pipe_fd, infile_fd);
	cpid2 = childpr2(argv, envp, pipe_fd, outfile_fd);
	closefunction(pipe_fd, infile_fd, outfile_fd);
	waitpid(cpid1, NULL, 0);
	waitpid(cpid2, NULL, 0);
	exit(EXIT_SUCCESS);
}
