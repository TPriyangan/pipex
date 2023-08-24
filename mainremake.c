void  openfiles(char *infile, char *outfile)
{
  int	infile_fd;
  int outfile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd == -1)
	{
		perror("open infile_fd failure");
		exit(EXIT_FAILURE);
	}
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1)
	{
		perror("open outfile_fd failure");
		exit(EXIT_FAILURE);
	}
  return(0);
}

void childprocess1(char *argv[], char *envp[], int pipe_fd[], int infile_fd,)
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
	int			cmd2pipefd[2];
	pid_t		childpid;
	ssize_t		read_bytes;
	
	/*check argument count*/
	if (argc != 5)
	{
		perror("argc !=5");
		exit(EXIT_FAILURE);
	}
	/*Opening input and output files*/
  openfiles(argv[1], argv[4]);
	/*CREATING A PIPE*/
	int	pipe_fd[2];
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe creation failure");
		exit(EXIT_FAILURE);
	}
	/*FORKING CHILD PROCESSES*/
	childprocess1(argv, envp, pipe_fd, infile_fd);
  childprocess2(argv, envp, pipe_fd, outfile_fd);
	/**/
	closefunction(pipefd, infile_fd, outfile_fd, pid1, pid2);
}
