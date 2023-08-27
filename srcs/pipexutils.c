/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:13:40 by tpriyang          #+#    #+#             */
/*   Updated: 2023/08/27 16:43:30 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}*/

void	free_string_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*find_path(char *cmd, char **envp)
{
	char	*path_variable;
	char	*full_path;

	path_variable = find_path_variable(envp);
	if (path_variable == NULL)
		return (NULL);
	full_path = search_executable_in_paths(cmd, path_variable);
	free(path_variable);
	return (full_path);
}

char	*find_path_variable(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (ft_strdup(envp[i] + 5));
		}
		i++;
	}
	return (NULL);
}

char	*search_executable_in_paths(char *cmd, char *path_variable)
{
	char	**paths;
	char	*full_path;
	int		i;

	paths = ft_split(path_variable, ':');
	full_path = NULL;
	i = 0;
	while (paths[i] != NULL)
	{
		full_path = create_full_path(cmd, paths[i]);
		if (full_path != NULL && access(full_path, F_OK) == 0)
		{
			free_string_array(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_string_array(paths);
	return (NULL);
}

char	*create_full_path(char	*cmd, char *path)
{
	char	*full_path;
	char	*full_path_result;

	full_path = ft_strjoin(path, "/");
	full_path_result = ft_strjoin(full_path, cmd);
	free(full_path);
	return (full_path_result);
}

void	command(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
	{
		perror("ft_split failed");
		exit(EXIT_FAILURE);
	}
	path = find_path(cmd[0], envp);
	if (path == NULL)
	{
		perror("Command not found");
		free(cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("execve failed");
		free(cmd);
		exit(EXIT_FAILURE);
	}
}
