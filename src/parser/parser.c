#include "../../inc/minishell.h"
// void tokenize_env(t_token **tmp2, t_token **tmp, t_token **head)
// {
//     char *env;
//     env = getenv((*tmp)->token);
//     if(!env)
//     {
//         printf("2 env: %s\n", env);
//         env = ft_strdup("");
//     }
//     else
//     {
//         printf("2 env: %s\n", env);
//         env = ft_strdup(env);
//     }
//     (*tmp) = tokenizer(env);
//     add_top(*tmp2, *tmp);
//     if (*tmp)
//         erase_one(head, (*tmp2));
//     else
//     {
//         free((*tmp2)->token);
//         (*tmp2)->token = NULL;
//         (*tmp2)->token = env;
//     }
//     tmp = tmp2;
// }

// t_token *prueba_env(t_token *head)
// {
//     t_token *tmp;
//     t_token *tmp2;
//     tmp = head;
//     // char *env;
//     while(tmp)
//     {
//         if(tmp->type == ENV)
//         {
//             tmp2 = tmp;
//             printf("1 env: %s\n", tmp->token);
//             tokenize_env(&tmp2, &tmp, &head);
//         }
//         if(tmp)
//             tmp = tmp->next;
//     }
//     tmp = head;
//     return (head);
// }

void tokenize_env(t_token **tmp2, t_token **tmp, t_token **head)
{
    char *env;
    t_token *new_tokens;

    env = getenv((*tmp)->token);
    if(!env)
        env = ft_strdup("");
    else
        env = ft_strdup(env);
    new_tokens = tokenizer(env);
    if (new_tokens)
    {
        add_top(*tmp2, new_tokens);
        erase_one(head, *tmp2);
        *tmp = new_tokens;
    }
    else
    {
        free((*tmp2)->token);
        (*tmp2)->token = env;
    }
}

t_token *prueba_env(t_token *head)
{
    t_token *tmp = head;
    t_token *tmp2;
    while (tmp)
    {
        if (tmp->type == ENV)
        {
            tmp2 = tmp;
            printf("1 env: %s\n", tmp->token);
            tokenize_env(&tmp2, &tmp, &head);
        }
        tmp = tmp->next;
    }
    return head;
}

// t_token *check_bonus_token(t_token *head)
// {
//     t_token *tmp;
//     int     type_bonus;

//     tmp = head;
//     type_bonus = 0;
//     while(tmp)
//     {
//         if(tmp->type == AND)
//             type_bonus = AND;
//         else if(tmp->type == OR)
//             type_bonus = OR;
//         tmp = tmp->next;
//     }
//     tmp = head;
//     tmp = assign_bonus_token(tmp, type_bonus);
//     return (tmp);
// }

// t_token *assign_bonus_token(t_token *head, int type_bonus)
// {
//     t_token *tmp;
//     t_token *tmp2;

//     tmp = head;
//     tmp2 = head;
//     while(tmp2)
//     {
//         if(type_bonus == AND)
//             tmp2->and = 1;
//         else if(type_bonus == OR)
//             tmp2->or = 1;
//         if(tmp2->type == PAREN)
//         {
//             // tmp2 = tokenizer(tmp->token);
//             add_token(&tmp, tokenizer(tmp->token));
//         }
//         tmp2 = tmp2->next;
//     }
//     return (tmp);
// }

