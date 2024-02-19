/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:23:08 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/19 12:46:59 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;
    int     i;

    i = 0;
    path = NULL;
	if (!*argv)
		ft_error("Error: invalid argument");
	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_error("Error: split failed");
	if (relative_path(cmd, &path) == 0)
    {
        if (cmd[0])
		    path = path_getter(cmd[0], env);
    }
	if (path && execve(path, cmd, env) == -1)
	{
		ft_free(cmd);
		ft_error("Error: execve failed");
	}
}

void	ft_pipex(int argc, char **argv, char **envp)
{
	int		**fd;
	pid_t	child1;
	pid_t	child2;

	fd = ft_init();
	if (pipe(fd) == -1)
		ft_error("Error: pipe failed");
	child1 = ft_first_child(fd, argv[2], envp);
	child2 = ft_final_child(fd, argv[4], envp);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		ft_error("Error: invalid number of arguments");
	if (argc == 5)
		ft_pipex(argc, argv, envp);
	return (0);
}
