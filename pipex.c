/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:23:08 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/20 12:25:00 by smeixoei         ###   ########.fr       */
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
		ft_free_matrix(cmd);
		ft_error("Error: execve failed");
	}
}

void	ft_pipex(int argc, char **argv, char **env)
{
	int		**fd;
	pid_t	child;
	int		heredoc;

	fd = ft_init();
	heredoc = ft_check_here_doc(fd, argc, argv);
	if (pipe(fd[2]) < 0)
		ft_error("Error: pipe failed");
	ft_first_child(fd, argv[2 + heredoc], env);
	child = ft_final_child(fd, argv[argc - 2], env);
	if (heredoc)
		unlink("here_doc");
	ft_waitchild(child);

}

void	pipex_bonus(int ac, char **av, char **env)
{
	int		**fd;
	int		pos;
    int     here_doc;
	pid_t	child;

    fd = ft_init();
	pos = 2;
	here_doc = ft_check_here_doc(fd, ac, av);
	if (pipe(fd[2]) < 0)
		ft_error("pipex");
    ft_first_child(fd, av[2 + here_doc], env);
    pos += here_doc;
	while (ac - 2 > ++pos)
		ft_middle_child(fd, av[pos], env);
	child = ft_final_child(fd, av[ac - 2], env);
    if (here_doc)
        unlink("here_doc");
	ft_waitchild(child);
}

int	main(int argc, char **argv, char **env)
{
	if (BONUS == 0 && argc == 5)
		ft_pipex(argc, argv, env);
	else if (BONUS == 1 && argc >= 5)
		pipex_bonus(argc, argv, env);
	else
		ft_putendl_fd("Error: invalid arguments", STDERR_FILENO);
	return (0);
}
