/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 set_subcommand.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: crmanzan <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/11/03 17:53:44 by crmanzan		   #+#	  #+#			  */
/*	 Updated: 2024/11/03 17:54:30 by crmanzan		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */
#include "../../inc/minishell.h"

static t_token	*find_subcommand_tokens(t_token *token, int *parenthesis_count)
{
	while (token && *parenthesis_count > 0)
	{
		if (token->syntaxis == L_PAREN)
			(*parenthesis_count)++;
		else if (token->syntaxis == R_PAREN)
			(*parenthesis_count)--;
		token = token->next;
	}
	return (token);
}

void	set_subcommand(t_cmd **cmd, t_token **tkn_p)
{
	t_cmd	*sub_cmd;
	t_token	*start_token;
	int		parenthesis_count;

	if (!(*cmd))
		*cmd = add_command(cmd);
	if (!(*cmd))
		return (lstclear(cmd, del_command));
	start_token = (*tkn_p)->next;
	parenthesis_count = 1;
	*tkn_p = find_subcommand_tokens(start_token, &parenthesis_count);
	sub_cmd = parser(start_token);
	if (!sub_cmd)
		return (lstclear(cmd, del_command));
	(*cmd)->subcommand = sub_cmd;
	(*cmd)->parenthesis = 1;
}
