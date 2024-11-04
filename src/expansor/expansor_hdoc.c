/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_hdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angeln <anovoa@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 01:19:59 by angeln            #+#    #+#             */
/*   Updated: 2024/11/04 01:20:00 by angeln           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*append_str(char *result, char *str)
{
	char	*new_result;

	if (!result)
		return (str);
	new_result = (char *)malloc(ft_strlen(result) + ft_strlen(str) + 1);
	if (!new_result)
		return (NULL);
	ft_strncpy(new_result, result, ft_strlen(result) + 1);
	ft_strlcat(new_result, str, ft_strlen(result) + ft_strlen(str) + 1);
	free(result);
	free(str);
	return (new_result);
}

static char	*handle_env_var(char *line, int *i, t_env *env)
{
	int		start;
	char	*var_name;
	char	*env_value;

	start = *i;
	while (line[*i] && (ft_isalpha(line[*i]) || line[*i] == '_'))
		(*i)++;
	var_name = ft_strndup(&line[start], *i - start);
	if (!var_name)
		return (NULL);
	env_value = ft_getenv(var_name, env);
	free(var_name);
	if (env_value)
		return (ft_strdup(env_value));
	return (ft_strdup(""));
}

static char	*parse_and_append_env_var(char *result,
				t_parse_state *state, t_env *env, int is_hdoc)
{
	char	*temp;

	if (state->start < state->i)
	{
		temp = ft_strndup(&state->line[state->start], state->i - state->start);
		result = append_str(result, temp);
	}
	state->i++;
	if (!is_hdoc)
		temp = handle_env_var(state->line, &state->i, env);
	else
		temp = ft_strndup(&(state->line)[state->start],
				(state->i) - state->start);
	result = append_str(result, temp);
	state->start = state->i;
	return (result);
}

static char	*parse_double_quote_content(char *line, int *i, t_env *env,
			int is_hdoc)
{
	char			*result;
	char			*temp;
	t_parse_state	state;

	state.line = line;
	state.i = *i;
	state.start = *i;
	result = NULL;
	result = append_str(result, ft_strdup("\'"));
	while (state.line[state.i] && state.line[state.i] != '\'')
	{
		if (state.line[state.i] == '$' && (ft_isalpha(state.line[state.i + 1])
				|| state.line[state.i + 1] == '_'))
			result = parse_and_append_env_var(result, &state, env, is_hdoc);
		else
			state.i++;
	}
	if (state.start < state.i)
	{
		temp = ft_strndup(&state.line[state.start], state.i - state.start);
		result = append_str(result, temp);
	}
	result = append_str(result, ft_strdup("\'"));
	*i = state.i;
	return (result);
}

t_token	*expansor_hdoc(t_token *head, t_env **env, int is_quoted)
{
	t_token	*tmp;
	t_token	*tmp2;
	int		i;
	char	*new_tokens;

	tmp = head;
	while (tmp)
	{
		if (tmp->type == ENV && !is_quoted)
		{
			tmp2 = tmp;
			tokenize_env(&tmp2, &tmp, &head, env);
		}
		else if (tmp->type == SINGLE_QUOTE && !is_quoted)
		{
			i = 1;
			new_tokens = parse_double_quote_content((tmp)->token, &i, *env, 0);
			free((tmp)->token);
			(tmp)->token = new_tokens;
		}
		tmp = tmp->next;
	}
	return (head);
}
