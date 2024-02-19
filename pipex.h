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

int	**ft_init(void);
pid_t	ft_first_child(int **fd, char **argv, char **env);
void	ft_middle_child(int **fd, char **argv, char **env);
pid_t	ft_final_child(int **fd, char **argv, char **env);
void	ft_pipex(int argc, char **argv, char **env);
int 	ft_check_here_doc(int **fd, int argc, char **argv);
int		ft_heredoc(char *argv1, char *argv2);
void	ft_reddirect(int **fd, int nbr);
void	ft_exec(char *argv, char **env);
int		path_checker(char **env);
char	*path_getter(char *cmd, char **env);
int		relative_path(char **cmd, char **path);

// Libft functions
void	ft_error(char *str);
void	ft_free(char **str);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif