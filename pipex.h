/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:58:55 by smeixoei          #+#    #+#             */
/*   Updated: 2024/03/05 12:59:31 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>
# include "./libft/libft.h"

# define BONUS 1

// UWU

void    ft_pipex(int argc, char **argv, char **env);
void    ft_pipex_bonus(int argc, char **argv, char **env);
void    ft_error(char *str);
int		ft_heredoc(char *argv1, char *argv2);
void    ft_first_cmd(int (*fd)[2], char **argv, char **env);
void    ft_mid_cmd(int (*fd)[2], char **argv, char **env);
pid_t    ft_last_cmd(int (*fd)[2], char **argv, char **env, int argc);
void	ft_waitchild(pid_t child);
char	*ft_get_path(char *cmd, char **env);
int		ft_relative_path(char **cmd, char **path);
void	ft_execute(char *argv, char **env);

// // ALEPITO

// int	    **ft_init(void);
// pid_t	ft_first_child(int **fd, char *argv, char **env);
// void	ft_middle_child(int **fd, char *argv, char **env);
// pid_t	ft_final_child(int **fd, char *argv, char **env);
// void	ft_pipex(int argc, char **argv, char **env);
// int 	ft_check_here_doc(int **fd, int argc, char **argv);
// int		ft_heredoc(char *argv1, char *argv2);
// void	ft_reddirect(int **fd, int nbr);
// void	ft_exec(char *argv, char **env);
// int		ft_path_checker(char **env);
// char	*ft_path_getter(char *cmd, char **env);
// int		ft_relative_path(char **cmd, char **path);
// void	ft_waitchild(pid_t child);

// // Libft functions
// void	ft_error(char *str);
// void	ft_free_matrix(char **str);

#endif