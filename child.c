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

void	ft_manage_fd(int **fd, int i)
{
	if (i == 1)
	{

	}
	else if (i == 2)
	{

	}
	else if (i == 3)
	{

	}
}

void    ft_first_cmd(int **fd, char **argv, char **env)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		ft_error("Error: fork");
	if (child == 0)
	{
		ft_manage_fd(fd, 1);
		ft_exec(argv[1], &argv[1], env);
	}
}

void    ft_mid_cmd(int **fd, char **argv, char **env)
{

}

pid_t    ft_last_cmd(int **fd, char **argv, char **env)
{
	
}
