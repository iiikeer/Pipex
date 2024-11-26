/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:36:23 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/19 17:04:29 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*check_cmd_path(char *cmd, char *path_prefix)
{
	char	*temp_path;
	char	*cmd_path;
	
	temp_path = ft_strjoin(path_prefix, "/");
	if (!temp_path)
		return (NULL);
	cmd_path = ft_strjoin(temp_path, cmd);
	free(temp_path);
	if (!cmd_path)
		return (NULL);
	if (access(cmd_path, X_OK) == 0)
		return (cmd_path);
	free(cmd_path);
	return (NULL);
}
