#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
void  openfiles(char *infile, char *outfile, int *infile_fd, int *outfile_fd)
{
	int file_permissions;
	file_permissions = 0777;
	*infile_fd = open(infile, O_RDONLY);
	if (*infile_fd == -1)
	{
		perror("open infile_fd failure");
		exit(EXIT_FAILURE);
	}
	*outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, file_permissions);
	if (*outfile_fd == -1)
	{
		perror("open outfile_fd failure");
		exit(EXIT_FAILURE);
	}
}

void childprocess1(char *argv[], char *envp[], int pipe_fd[], int infile_fd)
{
  pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork failure child1");
		exit(EXIT_FAILURE);
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
}
void childprocess2(char *argv[], char *envp[], int pipe_fd[], int outfile_fd)
{
	pid_t	pid2;
  
  pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork failure child2");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(pipe_fd[0]);
		command(argv[3],envp);
		exit(EXIT_SUCCESS);
	}
}
void closefunction(int pipe_fd[], int infile_fd, int outfile_fd, int pid1, int pid2)
{
  close(pipe_fd[0]);
	close(pipe_fd[1]);
	/*close files*/
	close(infile_fd);
	close(outfile_fd);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	exit(EXIT_SUCCESS);
	/*end*/
}
int	main(int argc, char *argv[], char *envp[])
{
	int	infile_fd;
	int outfile_fd;
	int	pipe_fd[2];
	/*check argument count*/

	infile_fd = -1;
	outfile_fd = -1;
	if (argc != 5)
	{
		perror("argc !=5");
		exit(EXIT_FAILURE);
	}
	/*Opening input and output files*/
  openfiles(argv[1], argv[4]);
	/*CREATING A PIPE*/
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe creation failure");
		exit(EXIT_FAILURE);
	}
	/*FORKING CHILD PROCESSES*/
	childprocess1(argv, envp, pipe_fd, infile_fd);
  childprocess2(argv, envp, pipe_fd, outfile_fd);
	/**/
	closefunction(pipe_fd, infile_fd, outfile_fd, pid1, pid2);
}
