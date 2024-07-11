/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_builtin_tokenizer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:23:03 by anovoa            #+#    #+#             */
/*   Updated: 2024/07/11 12:19:35 by anovoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* This function calls builtins. For test purposes only */
t_token	*mock_builtin_tokenizer(t_token *head)
{
	if (!head)
		return (NULL);
	if (!ft_strncmp(head->token, "zorionak"))
	{
		if (debug)
			debug = 0;
		else
			debug = 1;//Global variable for testing only. DELETE.
	}
	if (!ft_strncmp(head->token, "echo"))
		echo(head->next);
	return (head);
}
