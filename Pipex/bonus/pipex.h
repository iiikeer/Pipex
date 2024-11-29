/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:00:01 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 15:17:31 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h> 
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	char			**cmd;
	char			*path;
	pid_t			pid;
	struct s_pipex	*next;
}	t_pipex;

typedef struct s_info
{
	int				argc;
	char			**argv;
	char			**env;
}	t_info;

//CHECK PIPEX
int		check_argv(int argc, char **argv);
void	check_file(t_pipex **pipex, t_info *info, int fds[2]);
void	fill_here_doc(char *limit, int fd);
void	check_set_cmd_paths(t_pipex **pipex, t_info *info);
void	check_cmd_path(t_pipex **pipex, t_info *info, char **paths, int i);
void	set_cmd_paths(t_pipex *pipex, char **paths, char *cmd);
char	*check_path(char *cmd, char *path_prefix);

//PIPEX
void	exec_pipex(t_pipex **pipex, t_info *info, int pipe_fd[2], int fds[2]);
int		exec_cmd(t_pipex *pipe, t_info *info, int input_fd, int output_fd);
void	close_pipex(t_pipex **pipex, t_info *info, int pipe_fd[2], int fds[2]);

//UTILS
void	ft_free_pipex(t_pipex **pipex);
void	ft_free(char **array);
void	ft_error(t_pipex **pipex, t_info *info);

//STACK UTILS
void	ft_add_back(t_pipex **stack, t_pipex *new);
t_pipex	*ft_last_node(t_pipex *stack);
t_pipex	*ft_stacknew(char **command);
t_info	*ft_nodenew(int argc, char **argv, char **env);

#endif