#include "../../inc/minishell.h"

t_token *handle_special_dollar(char *line, int *i)
{
	int		start;
	char	*value;

	start = ++*i;
	while (line[*i] && !ft_istoken(line[*i]) && !ft_isalpha(line[*i]))
	{
		if (line[*i] == '&' && line[*i + 1] == '&')
			break ;
		
		if(line[*i] == '$' && (ft_isalpha(line[*i + 1]) || line[*i + 1] == '_'))
			break ;
		(*i)++;
	}
	value = ft_strndup(&line[start - 1], (*i)- start + 1);
	printf("value: %s\n", value);
	if (!value)
		return (NULL);
	(*i) -= 1;
	return (new_token(ARG, value, 0));
}



t_token	*handle_dollar(char *line, int *i)
{
	int		start;
	char	*value;

	start = *i;
	printf("holi\n");
	if(!ft_isalpha(line[start + 1]) && line[start + 1] != '_')
		return (handle_special_dollar(line, i));
	printf("handle %s\n", &line[start]);

	start = ++*i;
	while (line[*i] && (ft_isalpha(line[*i]) || line[*i] == '_'))
	{
		if (line[*i] == '&' && line[*i + 1] == '&')
			break ;
		(*i)++;
	}
	printf("start: %d\n", start);
	printf("i: %d\n", *i);
	value = ft_strndup(&line[start], *i - start);
	printf("value: %s\n", value);
	if (!value)
		return (NULL);
	(*i)--;
	return (new_token(ENV, value, 0));
}
