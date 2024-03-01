/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:50:16 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/21 20:50:16 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void    ft_first_cmd(int (*fd)[2], char **argv, char **env)
{
	pid_t	pid_in;
	int		fd_in;;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		ft_error("Error: open");
	pid_in = fork();
	if (pid_in < 0)
		ft_error("Error: fork");
	if (pid_in == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd[1][0]);
		close(fd[1][1]);
		dup2(fd[0][1], STDOUT_FILENO);
		close(fd[0][0]);
		ft_execute(argv[2], env);
	}
	close(fd_in);
	close(fd[0][1]);
}

void    ft_mid_cmd(int (*fd)[2], char **argv, char **env)
{

}

pid_t    ft_last_cmd(int (*fd)[2], char **argv, char **env, int argc)
{
	pid_t	pid_out;
	int		fd_out;

	if (ft_strncmp("here_doc", argv[1], 9) == 0)
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	pid_out = fork();
	if (pid_out < 0)
		ft_error("Error: fork");
	if (pid_out == 0)
	{
		dup2(fd[0][0], STDIN_FILENO);
		close(fd[0][0]);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		ft_execute(argv[argc - 2], env);
	}
	close(fd[0][0]);
	close(fd_out);
	return (pid_out);
}
