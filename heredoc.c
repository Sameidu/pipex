/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:52:41 by smeixoei          #+#    #+#             */
/*   Updated: 2024/02/20 11:41:54 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_check_here_doc(int **fd, int argc, char **argv)
{
    int  here_doc;
    char *infile;
    char *outfile;

    here_doc = 0;
    infile = argv[1];
    outfile = argv[argc - 1];
    if (ft_strncmp("here_doc", infile, 9) == 0)
        here_doc = 1;
    if (here_doc)
        fd[0][0] = ft_heredoc(infile, argv[2]);
    else
        fd[0][0] = open(infile, O_RDONLY);
    if (here_doc)
        fd[0][1] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0666);
    else
        fd[0][1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    return (here_doc);
}

int	ft_heredoc(char *argv1, char *argv2)
{
	char	*line;
	int		temp_fd;
    
	temp_fd = open(argv1, O_CREAT | O_RDWR | O_TRUNC, 0777);
	while (1)
	{
		ft_putendl_fd("heredoc XD >>", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, argv2, ft_strlen(argv2) + 1) == 10)
        {
            free(line);
			break ;
        }
		write(temp_fd, line, ft_strlen(line));
		free(line);
	}
	close(temp_fd);
	temp_fd = open(argv1, O_RDONLY);
	return (temp_fd);
}
