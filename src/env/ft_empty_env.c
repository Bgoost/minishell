/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:57:39 by crmanzan          #+#    #+#             */
/*   Updated: 2024/11/03 20:01:25 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

int	ft_issafedup(t_env **tmp, char *name, char *value)
{
	*tmp = (t_env *)malloc(sizeof(t_env));
	if (!tmp)
		return (0);
	(*tmp)->key_name = ft_strdup(name);
	if (!(*tmp)->key_name)
		return (0);
	(*tmp)->value = ft_strdup(value);
	if (!(*tmp)->value)
		return (0);
	return (1);
}

void	ft_empty_env(t_env **tmp)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		exit(1);
	if (!ft_issafedup(tmp, "PWD", pwd))
		exit(1);
	if (!ft_issafedup(&((*tmp)->next), "OLDPWD", pwd))
		exit(1);
	if (!ft_issafedup(&((*tmp)->next->next), "SHLVL", "1 "))
		exit(1);
	(*tmp)->next->next->next = NULL;
	free(pwd);
}
