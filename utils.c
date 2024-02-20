/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:31:26 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/20 12:47:50 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_waitchild(pid_t child)
{
	int	status;
	int	pid;
	int	exit_status;

	pid = 1;
	while (pid != -1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == child)
		{
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
		}
	}
	exit(exit_status);
}

int	**ft_init(void)
{
	int	i;
	int	**fd;

	i = 0;
	fd = malloc(3 * sizeof(int *));
	if (!fd)
		ft_error("Error: malloc failed");
	while (i < 3)
	{
		fd[i] = malloc(2 * sizeof(int));
		if (!fd[i])
			ft_error("Error: malloc failed");
		i++;
	}
	return (fd);
}