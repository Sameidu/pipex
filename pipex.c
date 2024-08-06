/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:34:20 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/21 19:34:20 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_waitchild(pid_t *child, int cmds)
{
	int		status;
	pid_t	wait;
	int		i;

	i = 0;
	while (i < cmds - 1)
	{
		wait = waitpid(child[i], &status, 0);
		if (wait == -1)
			perror("Error: command not found");
		else
		{
			if (WIFEXITED(status))
			{
				if (WEXITSTATUS(status) != 0)
					perror("Error: command not found");
			}
		}
		i++;
	}
}

void	ft_pipex(int argc, char **argv, char **env)
{
	int		fd[2][2];
	pid_t	child[argc - 2];
	int i = 0;

	if (pipe(fd[0]) < 0)
		perror("Error: pipe");
	child[i] = ft_first_cmd(fd, argv, env);
	i++;
	child[i] = ft_last_cmd(fd, argv, env, argc);
	ft_waitchild(child, i);
}

void	ft_pipex_bonus(int argc, char **argv, char **env)
{
	int		fd[2][2];
	int		cmds;
	int		here_doc;
	int		i;
	pid_t	child[argc - 2];

	here_doc = 0;
	i = 0;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		here_doc = 1;
	if (pipe(fd[0]) < 0)
		perror("Error: pipe");
	cmds = 2 + here_doc;
	child[i++] = ft_first_cmd(fd, argv, env);
	while (++cmds < argc - 2)
		child[i++] = ft_mid_cmd(fd, argv, env, cmds);
	child[i] = ft_last_cmd(fd, argv, env, argc);
	ft_waitchild(child, cmds);
}

// void	ft_leaks(void)
// {
// 	system("leaks -q pipex");
// }

int	main(int argc, char **argv, char **env)
{
	// atexit(ft_leaks);
	if (argc < 5 || ((ft_strncmp(argv[1], "here_doc", 9) == 0) && argc < 6))
		perror("Error: invalid arguments");
	if (BONUS == 0 && argc == 5)
		ft_pipex(argc, argv, env);
	else if (BONUS == 1 && argc >= 5)
		ft_pipex_bonus(argc, argv, env);
	else
		perror("Error: invalid arguments");
	return (0);
}
