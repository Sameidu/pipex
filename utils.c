/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:20:02 by smeixoei          #+#    #+#             */
/*   Updated: 2024/08/05 19:20:02 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_free_split(char **split)
{
    int i;

    i = 0;
    if (split)
    {
        while (split[i])
        {
            free(split[i]);
            i++;
        }
        free(split);
    }
}