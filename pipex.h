/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:49:03 by tpriyang          #+#    #+#             */
/*   Updated: 2023/08/27 16:43:07 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"

void	free_string_array(char **array);
char	*find_path(char *cmd, char **envp);
char	*find_path_variable(char **envp);
char	*search_executable_in_paths(char *cmd, char *path_variable);
char	*create_full_path(char *cmd, char *path);
void	command(char *argv, char **envp);
#endif
