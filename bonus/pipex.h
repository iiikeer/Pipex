/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:00:01 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/26 12:51:01 by iullibar         ###   ########.fr       */
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
	int				infile;
	int				outfile;
	char			**cmd;
	char			*path;
	pid_t			pid;
	struct s_pipex	*next;
}	t_pipex;

void	check_file(t_pipex **pipex, char **argv, int fds[2]);
void	check_set_cmd_paths(t_pipex **pipex, int argc, char **argv, char **env);
void	set_cmd_paths(t_pipex *pipex, char **paths, char *cmd);
char	*check_cmd_path(char *cmd, char *path_prefix);
void	create_pipe(t_pipex **pipex, int pipe_fd[2]);
void	exec_pipex(t_pipex **pipex, int pipe_fd[2], int fds[2], char **env);
void	exec_cmd1(t_pipex *pipex, int pipe_fd[2], int fds[2], char **env);
void	exec_cmd2(t_pipex *pipex, int pipe_fd[2], int fds[2], char **env);
void	close_pipex(t_pipex **pipex, int pipe_fd[2], int fds[2]);
void	ft_error(t_pipex **pipex);
void	ft_free_pipex(t_pipex **pipex);

//STACK UTILS
void	ft_add_back(t_pipex **stack, t_pipex *new);
t_pipex	*ft_last_node(t_pipex *stack);
t_pipex	*ft_stacknew(char **command);

#endif