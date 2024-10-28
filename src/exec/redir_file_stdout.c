/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_stdout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angeln <anovoa@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:42:21 by angeln            #+#    #+#             */
/*   Updated: 2024/10/27 23:00:23 by angeln           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Opens or creates the given filename and redirects output to it.
 * File permissions rw-r--r-- */
int	redir_file_stdout(char *filename, int mode)
{
	int	fd;

	fd = 0;
	if (mode == REDIR_OUT)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mode == APPEND)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)//err msg?
		return (1);
	if (dup2(fd, 1) == -1)
		return (1);
	if (close(fd) == -1)
		return (1);
	return (0);
}