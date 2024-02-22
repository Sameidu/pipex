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

# include "pipex.h"

void    ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void    ft_pipex(int argc, char **argv, char **env)
{
	int		fd[2][2];
	pid_t	child;

	if (pipe(fd[2]) < 0)
		ft_error("Error: pipe");
	ft_first_cmd(fd, argv, env);
	child = ft_last_cmd(fd, argv, env);
	ft_waitchild(child);
}

void    ft_pipex_bonus(int argc, char **argv, char **env)
{
	int		fd[2][2];
	int		cmds;
	int		here_doc;
	pid_t	child;

	here_doc = ft_check_heredoc();
	if (pipe(fd[2]) < 0)
		ft_error("Error: pipe");
	cmds = 1 + here_doc;
	ft_first_cmd();
	while (++cmds < argc - 2)
		ft_mid_cmd();
	child = ft_last_cmd();
	ft_waitchild(child);	
}

int main(int argc, char **argv, char **env)
{
	if (argc < 5 || (ft_strncmp(argv[1], "here_doc", 9) == 0) && argc < 6)
		ft_error("Error: invalid arguments");
	if (BONUS == 0 && argc == 5)
		ft_pipex(argc, argv, env);
	else if (BONUS == 1)
		ft_pipex_bonus(argc, argv, env);
	return (0);
}
