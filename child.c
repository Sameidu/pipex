/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:31:50 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/19 13:00:52 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_reddirect(int **fd, int nbr)
{
	if (nbr == 1)
	{
		dup2(fd[0][0], STDIN_FILENO);
		dup2(fd[2][1], STDOUT_FILENO);
		close(fd[2][0]);
		close(fd[2][1]);
	}
	else if (nbr == 2)
	{
		dup2(fd[1][0], STDIN_FILENO);
		dup2(fd[2][1], STDOUT_FILENO);
		close(fd[1][0]);
		close(fd[1][1]);
	}
	else if (nbr == 3)
	{
		dup2(fd[2][0], STDIN_FILENO);
		dup2(fd[0][1], STDOUT_FILENO);
	}
	else
		ft_error("Error: invalid nbr");
}

pid_t	ft_first_child(int **fd, char **argv, char **env)
{
	pid_t	in;

	in = fork();
	if (in < 0)
		ft_error("Error: fork failed");
	if (in == 0)
	{
		ft_reddirect(fd, 1);
		ft_exec(argv, env);
	}
	close(fd[2][1]);
	close(fd[2][0]);
	return (in);
}

void	ft_middle_child(int **fd, char **argv, char **env)
{
	pid_t	mid;

	fd[1][0] = fd[2][0];
	fd[1][1] = fd[2][1];
	pipe(fd[2]);
	{
		mid = fork();
		if (mid < 0)
			ft_error("Error: fork failed");
		if (mid == 0)
		{
			ft_reddirect(fd, 2);
			ft_exec(argv, env);
		}
		close(fd[2][1]);
		close(fd[1][0]);
	}
}

pid_t	ft_final_child(int **fd, char **argv, char **env)
{
	pid_t	out;

	out = fork();
	if (out < 0)
		ft_error("Error: fork failed");
	if (out == 0)
	{
		ft_reddirect(fd, 3);
		ft_exec(argv, env);
	}
	return (out);
}
