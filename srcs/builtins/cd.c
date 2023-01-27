/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:01:49 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/27 18:57:50 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **tokens, char **env)
{
	char		*path;
	int			i;

	i = 1;
	path = tokens[i];
	if (!path)
	{	
		while (env[i])
		{
			if (ft_strncmp("HOME=", env[i], 5) == 0)
				chdir(env[i] + 5);
			i++;
		}
	}
	else if (chdir(path) == -1)
		ft_print_error(*tokens);
	else
	{
		i = 0;
		while (tokens[i])
		{
			path = ft_strjoin(path, tokens[i]);
			i++;
			if (tokens[i])
				path = ft_strjoin(path, " ");
			free(path);
		}
	}
	return (0);
}
