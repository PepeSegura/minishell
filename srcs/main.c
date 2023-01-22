/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:37:31 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/20 18:56:40 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc, (void)argv;
	ft_memset(&g_c, 0, sizeof(t_cosas));
	g_c.env = ft_get_env(env);
	g_c.dolar_q = 127;
	readline_create();
	exit(EXIT_SUCCESS);
	return (0);
}

	//ft_print_header();