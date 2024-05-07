/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 04:47:10 by juperez           #+#    #+#             */
/*   Updated: 2024/05/07 11:20:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

int	main(int ac, char *av[])
{
	if (ac > 1)
	{
		if (!strcmp(av[1], "--all") || !strcmp(av[1], "-a"))
		{
			ft_call_all_test(true, false, g_fmandatory);
			ft_call_all_test(false, false, g_fbonus);
		}
		else if (!strcmp(av[1], "--force") || !strcmp(av[1], "-f"))
		{
			ft_call_all_test(true, true, g_fmandatory);
			ft_call_all_test(false, true, g_fbonus);
		}
		else if (!strcmp(av[1], "--mandatory") || !strcmp(av[1], "-m"))
			ft_call_all_test(true, false, g_fmandatory);
		else if (!strcmp(av[1], "--bonus") || !strcmp(av[1], "-b"))
			ft_call_all_test(true, false, g_fbonus);
		else if (!strcmp(av[1], "--show") || !strcmp(av[1], "-s"))
			system(SHOW_FUNC);
		else if (!strcmp(av[1], "--help") || !strcmp(av[1], "-h"))
			ft_print_file(SHOW_HELP);
		else if (!strcmp(av[1], "--version") || !strcmp(av[1], "-v"))
			ft_print_file(SHOW_VERSION);
		else if (!ft_call_test(av[1]))
			printf("%s: invalid argument -- '%s'%s",
				basename(av[0]), av[1], ERROR_HELP);
	}
	else
		printf("%s: requires an argument%s", basename(av[0]), ERROR_HELP);
	return (EXIT_SUCCESS);
}
