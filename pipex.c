/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:00:41 by tpriyang          #+#    #+#             */
/*   Updated: 2023/08/05 16:16:19 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h> /*strerror*/

int	main(int argc, char *argv[])
{
	int			pipefd[2];
	char		buffer;
	pid_t		child_pid;

	if (argc != 2)
	{
		perror("argc != 2");
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe(pipefd) return -1");
		exit(EXIT_FAILURE);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork /child_pid == -1");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		close(pipefd[1]);
		while (read(pipefd[0], &buffer, 1) > 0)
			write(STDOUT_FILENO, &buffer, 1);
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		_exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd[0]);
		close(pipefd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
}
