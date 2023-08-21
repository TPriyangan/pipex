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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	k = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = (char *)malloc((i + j + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (k < i)
	{
		ptr[k] = s1[k];
		k++;
	}
	while (k < i + j)
	{
		ptr[k] = s2[k - i];
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(s));
	if (!str)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		while (i < len)
		{
			str[i] = s[i + start];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)(big + i));
	while (i < len && big[i])
	{
		j = 0;
		while (((char *)big)[i + j] == ((char *)little)[j] && (i + j < len))
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

static size_t	ft_nbr_mots(char const *s, char c)
{
	size_t	i;
	int		mot;

	i = 0;
	mot = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			mot++;
		}
	}
	return (mot);
}

static size_t	ft_lettres(char const *s, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	mots;
	char	**ptr;

	mots = 0;
	if (!s)
		return (NULL);
	ptr = (char **)malloc((ft_nbr_mots(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			ptr[mots] = ft_substr(s, i, ft_lettres(s, i, c));
			i = i + ft_lettres(s, i, c);
			mots++;
		}
	}
	ptr[mots] = 0;
	return (ptr);
}

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (NULL);
}

void	command(char *argv, char **envp)
{
	char	**cmd;
	int 	i;
	char	*path;
	
	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)	
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}


int	main(int argc, char *argv[], char *envp[])
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
	/*FORKING CHILD PROCESSES*/
	pid_t	pid1;
	pid_t	pid2;

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
		command(cmd[1], envp);
	}

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
		command(cmd[2],envp);
	}
	/**/
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
