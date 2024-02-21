/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:23:08 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/21 13:30:45 by smeixoei         ###   ########.fr       */
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
	if (ft_relative_path(cmd, &path) == 0)
    {
        if (cmd[0])
		    path = ft_path_getter(cmd[0], env);
    }
	if (path && execve(path, cmd, env) == -1)
	{
		ft_free_matrix(cmd);
		ft_error("Error: execve failed");
	}
}

void	ft_pipex(int argc, char **argv, char **env)
{
	int		**fd;
	pid_t	child;

	fd = ft_init();
	if (pipe(fd[2]) < 0)
		ft_error("Error: pipe failed");
	ft_first_child(fd, argv[2], env);
	child = ft_final_child(fd, argv[argc - 2], env);
	ft_waitchild(child);
}

void	ft_pipex_bonus(int argc, char **argv, char **env)
{
	int		**fd;
	pid_t	child;
	int		pos;
	int     here_doc;

	fd = ft_init();
	pos = 2;
	here_doc = ft_check_here_doc(fd, argc, argv);
	ft_first_child(fd, argv[2 + here_doc], env);
	pos += here_doc;
	while (argc - 2 > ++pos)
		ft_middle_child(fd, argv[pos], env);
	child = ft_final_child(fd, argv[argc - 2], env);
	if (here_doc)
		unlink("here_doc");
	ft_waitchild(child);
}

int	main(int argc, char **argv, char **env)
{
	if (argc < 5 || (ft_strncmp("here_doc", argv[1], 9) == 0 && argc < 6))
		ft_error("Error: invalid arguments");
	if (argc == 5)
		ft_pipex(argc, argv, env);
	else
		ft_pipex_bonus(argc, argv, env);
	return (0);
}
