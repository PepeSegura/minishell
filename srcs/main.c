/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:37:31 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/14 22:50:30 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	**environment;

	//argc = 0;
	//argv = NULL;
	(void)argc, (void)argv;
	//ft_print_header();
	environment = ft_get_env(env);
	readline_create(environment); /*añado input a la funcion*/
	exit(EXIT_SUCCESS);
	return (0);
}
