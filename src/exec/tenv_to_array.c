/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tenv_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angeln <anovoa@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:59:43 by angeln            #+#    #+#             */
/*   Updated: 2024/11/03 17:13:13 by anovoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	env_listlen(t_env *env);

char	**tenv_to_array(t_env *env)
{
	char	**env_arr;
	int		length;
	int		i;

	env_arr = ft_calloc(env_listlen(env) + 1, sizeof(char *));
	i = 0;
	if (!env_arr)
		print_and_kill("minishell: malloc", 1);
	while (env)
	{
		if (!env->value)
		{
			env = env->next;
			break ;
		}
		length = ft_strlen(env->key_name) + ft_strlen(env->value) + 2;
		env_arr[i] = ft_calloc(length, sizeof(char));
		if (!env_arr[i] && !free_split(env_arr))
			print_and_kill("minishell: malloc", 1);
		ft_strncpy(env_arr[i], env->key_name, length);
		ft_strlcat(env_arr[i], "=", length);
		ft_strlcat(env_arr[i++], env->value, length);
		env = env->next;
	}
	return (env_arr);
}

static int	env_listlen(t_env *env_list)
{
	int	count;

	count = 0;
	while (env_list)
	{
		count++;
		env_list = env_list->next;
	}
	return (count);
}
