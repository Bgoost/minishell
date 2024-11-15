/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:27:29 by crmanzan          #+#    #+#             */
/*   Updated: 2024/11/03 16:25:40 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

t_token	*get_token(char *line, int *i, t_env *env, int is_hdoc)
{
	t_token	*token;

	token = NULL;
	if (!is_hdoc)
		token = get_special_token(line, i);
	if (token)
		return (token);
	else if (line[*i] == '<' && line[*i + 1] == '<')
		token = create_token(HEREDOC, "<<", i);
	else if (line[*i] == '>' && line[*i + 1] == '>')
		token = create_token(APPEND, ">>", i);
	else if (line[*i] == '<')
		token = create_token(REDIR_IN, "<", i);
	else if (line[*i] == '>')
		token = create_token(REDIR_OUT, ">", i);
	else if (ft_isspace(line[*i]))
		token = handle_space(line, i);
	else if (line[*i] == '"')
		token = handle_double_quote(line, i, env, is_hdoc);
	else if ((line[*i] == '(' || line[*i] == ')'))
		token = handle_parenthesis(line, i);
	else
		token = handle_arg(line, i, is_hdoc);
	return (token);
}
