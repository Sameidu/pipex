/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:19:20 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/21 12:27:15 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_path_checker(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_path_getter(char *cmd, char **env)
{
	int		i;
	char	**env_path;
	char	*path;
	char	*cmd_path;

	i = ft_path_checker(env);
	if (!env[i])
		return (NULL);
	env_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (env_path[i])
	{
		path = ft_strjoin(env_path[i], "/");
		cmd_path = ft_strjoin(path, cmd);
        if (path)
		    free(path);
		if (access(cmd_path, X_OK) == 0)
		{
			ft_free_matrix(env_path);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	return (ft_free_matrix(env_path), NULL);
}

int	ft_relative_path(char **cmd, char **path)
{
	int	check;
    
    if (*cmd == NULL)
        return (0);
	check = 0;
    if (ft_strncmp(*cmd, "/", 1) == 0 || ft_strncmp(*cmd, "./", 2) == 0
		||  ft_strncmp(*cmd, "../", 2) == 0)
		check = 1;
	if (check == 1)
	{
        if (access(cmd[0], F_OK) == 0)
            *path = cmd[0];
        else
        {
            ft_free_matrix(cmd);
            ft_error("Error: command not found");
        }
    }
    return (check);
}
