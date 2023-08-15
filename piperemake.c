/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piperemake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:13:40 by tpriyang          #+#    #+#             */
/*   Updated: 2023/08/15 13:14:08 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	int			cmd2pipefd[2];
	char		*buffer;
	pid_t		childpid;
	ssize_t		read_bytes;
	
	/*check argument count*/
	if (argc != 5)
	{
		perror("argc !=5");
		exit(EXIT_FAILURE);
	}
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;

	infile = argv[1];
	outfile = argv[4];
	cmd1 = argv[2];
	cmd2 = argv[3];
	/*Opening input and output files*/
	int	infile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd == -1)
	{
		perror("open infile_fd failure");
		exit(EXIT_FAILURE);
	}
	int	outfile_fd;
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1)
	{
		perror("open outfile_fd failure");
		exit(EXIT_FAILURE);
	}
	/*CREATING A PIPE*/
	int	pipe_fd[2];
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe creation failure");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	/*FORKING CHILD PROCESSES*/
	pid_t	pid1;
	pid_t	pid2;

	pid1 =fork();
	if (pid1 == -1)
	{
		perror("fork failure child1");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0], STDIN_FILENO);
	}

	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork failure child2");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	/**/
	close(pipe_fd[0];
	/*close files*/
	close(infile_fd);
	close(outfile_fd);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	exit(EXIT_SUCCESS);
	/*end*/
}
