/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:03:35 by juperez           #+#    #+#             */
/*   Updated: 2024/03/16 09:16:26 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char	*g_atoi_tests[] = {
	"\t\n\v\f\r +00000042",
	" -42a",
	" a42",
	" -+--+42",
	"-2147483648",
	"2147483647",
	"0",
	"-00",
	"",
	"999999999999999",
	"999999999999999999999",
	"-9999999999999999999999",
	NULL
};

const char	*g_itoa_tests[] = {
	"42",
	"-42",
	"0",
	"-2147483648",
	"2147483647",
	"-1",
	"1",
	"100",
	NULL
};

const char	*g_str_tests[] = {
	"\t\n\v\f\r ",
	"Hello World!",
	"42",
	"#",
	"",
	NULL
};