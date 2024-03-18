/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 04:47:10 by juperez           #+#    #+#             */
/*   Updated: 2024/03/18 14:05:33 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

int	main(int ac, char *av[])
{
	if (ac > 1)
	{
		if (!strcmp(av[1], "--all") || !strcmp(av[1], "-a"))
		{
			ft_all_mandatory(true);
			ft_all_bonus(false);
		}
		else if (!strcmp(av[1], "--mandatory") || !strcmp(av[1], "-m"))
			ft_all_mandatory(true);
		else if (!strcmp(av[1], "--bonus") || !strcmp(av[1], "-b"))
			ft_all_bonus(true);
		else if (!strcmp(av[1], "--show") || !strcmp(av[1], "-s"))
			system("./show.sh");
		else if (!strcmp(av[1], "--help") || !strcmp(av[1], "-h"))
			ft_print_file("help");
		else if (!strcmp(av[1], "--version") || !strcmp(av[1], "-v"))
			ft_print_file("version");
		else if (!ft_check_argument(av[1], (const char **)av + 2, ac - 2))
			printf("%s: invalid argument -- '%s'%s",
				basename(av[0]), av[1], HELP);
	}
	else
		printf("%s: requires an argument%s", basename(av[0]), HELP);
	return (EXIT_SUCCESS);
}
