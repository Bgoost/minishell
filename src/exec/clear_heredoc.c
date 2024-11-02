/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:07:57 by anovoa            #+#    #+#             */
/*   Updated: 2024/11/02 12:10:29 by anovoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	clear_heredoc(t_file *target)
{
	if (target->heredoc_fd == -1)
		return (0);
	if (close(target->heredoc_fd) == -1)
		return (1);
	unlink("/tmp/temp_heredoc.txt");
	return (0);
}