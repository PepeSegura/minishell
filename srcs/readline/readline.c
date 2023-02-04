/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/03 23:49:45 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_exit(const char *command_buf)
{
	return (!ft_strcmp(command_buf, "exit")
		|| !ft_strcmp(command_buf, "quit") || !ft_strcmp(command_buf, "e")
		|| !ft_strcmp(command_buf, "q"));
}

void	expand_while(void)
{
	g_c.tok_count = 0;
	while (g_c.tokens[g_c.tok_count])
	{
		g_c.tokens[g_c.tok_count] = expan_token2(g_c.tokens[g_c.tok_count],
				g_c.env);
		if (token_is_symbol(g_c.tokens[g_c.tok_count]))
			g_c.pipas++;
		g_c.tok_count++;
	}
	g_c.tokens[g_c.tok_count] = NULL;
}

void	readline_create(void)
{
	const char	*command_buf;

	while (1)
	{
		command_buf = (const char *)readline(PROMPT);
		if (!command_buf)
		{
			dprintf(2, "agur");
			exit(0);
		}
		command_buf = ft_strtrim(command_buf, " ");
		if (!*command_buf) //TODO: eliminar espacios extras
			continue;
		if (read_exit(command_buf))
			break ;
		if (ft_strlen(command_buf) > 0)
			add_history(command_buf);
		if (!check_quotes(command_buf))
		{
			printf(OPEN_QUOTES);
			free((char *)command_buf);
			continue ;
		}
		g_c.tokens = malloc(sizeof(char *) * (count_tokens(command_buf) + 1));
		store_tokens(command_buf, g_c.tokens);
		if (double_symbols(g_c.tokens) == 1)
		{
			printf(BAD_SYMBOLS);
			ft_free_matrix(g_c.tokens);
			continue ;
		}
		g_c.tokens = tokens_to_pipas(g_c.tokens);
		ft_print_matrix(g_c.tokens, "PIPAS");
		expand_while();
		pipas_handler();	
	}
}
