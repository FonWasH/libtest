/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 04:47:10 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 04:20:42 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

int	main(int ac, char *av[])
{
	if (ac > 1)
	{
		if (!strcmp(av[1], "--all") || !strcmp(av[1], "-a"))
		{
			ft_mandatory(true);
			ft_bonus(false);
		}
		else if (!strcmp(av[1], "--mandatory") || !strcmp(av[1], "-m"))
			ft_mandatory(true);
		else if (!strcmp(av[1], "--bonus") || !strcmp(av[1], "-b"))
			ft_bonus(true);
		else if (!strcmp(av[1], "--show") || !strcmp(av[1], "-s"))
			system("./scripts/show.sh");
		else if (!strcmp(av[1], "--help") || !strcmp(av[1], "-h"))
			ft_print_file("docs/help");
		else if (!strcmp(av[1], "--version") || !strcmp(av[1], "-v"))
			ft_print_file("docs/version");
		else if (!ft_call_test(av[1], (void **)av + 2, ac - 2))
			printf("%s: invalid argument -- '%s'%s",
				basename(av[0]), av[1], HELP);
	}
	else
		printf("%s: requires an argument%s", basename(av[0]), HELP);
	return (EXIT_SUCCESS);
}
