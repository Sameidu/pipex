/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:31:26 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/19 12:45:15 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free(char **str)
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