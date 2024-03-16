/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 04:47:10 by juperez           #+#    #+#             */
/*   Updated: 2024/03/16 09:16:34 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

int	main(int ac, char *av[])
{
	if (ac > 1)
	{
		if (!strcmp(av[1], "--all") || !strcmp(av[1], "-a"))
		{
			ft_all_mandatory();
			ft_all_bonus();
		}
		else if (!strcmp(av[1], "--mandatory") || !strcmp(av[1], "-m"))
			ft_all_mandatory();
		else if (!strcmp(av[1], "--bonus") || !strcmp(av[1], "-b"))
			ft_all_bonus();
		else if (!strcmp(av[1], "--show") || !strcmp(av[1], "-s"))
			system(CMD_SHOW);
		else if (!strcmp(av[1], "--help") || !strcmp(av[1], "-h"))
			ft_print_file("help");
		else if (!strcmp(av[1], "--version") || !strcmp(av[1], "-v"))
			ft_print_file("version");
		else if (!ft_check_argument(av[1], (const char **)av + 2, ac - 2))
			printf("%s: invalid option -- '%s'\n%s", basename(av[0]), av[1], TRY_HELP);
	}
	else
		printf("%s: requires an option\n%s", basename(av[0]), TRY_HELP);
	return (EXIT_SUCCESS);
}
