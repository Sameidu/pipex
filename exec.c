/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:12:06 by smeixoei          #+#    #+#             */
/*   Updated: 2024/03/01 11:32:14 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

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
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
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
            ft_error("Error: command not found");
    }
    return (check);
}

void	ft_execute(char *argv, char **env)
{
	char	**cmd;
	char	*path;
    int     i;

	if (!*argv)
		ft_error("Error: invalid argument");
    i = 0;
    path = NULL;
	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_error("Error: split");
	if (ft_relative_path(cmd, &path) == 0)
    {
        if (cmd[0])
		    path = ft_path_getter(cmd[0], env);
    }
	if (path && execve(path, cmd, env) == -1)
	{
		free(path);
		ft_error("Error: execve failed");
	}
}
