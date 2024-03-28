/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:19:55 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 13:21:38 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static void	ft_putchar_isprint(char c)
{
	printf("%s'", DM);
	if (isprint(c))
		printf("%c", c);
	else
		printf("\\%02x", (unsigned char)c);
	printf("'%s ", X);
}

static void	ft_putstr_isprint(const char *str)
{
	if (!str)
		printf("%sNULL%s ", DM, X);
	else
	{
		printf("%s\"", DM);
		while (*str)
		{
			if (isprint(*str))
				printf("%c", *str);
			else
				printf("\\%02x", (unsigned char)*str);
			str++;
		}
		printf("\"%s ", X);
	}
}

static void	ft_print_intput(void)
{
	printf("%s", INPUT);
	if (g_presult.input_int)
		printf("%s%i%s ", DM, g_result.input_int, X);
	if (g_presult.input_sizet)
		printf("%s%zu%s ", DM, g_result.input_sizet, X);
	if (g_presult.input_chr)
		ft_putchar_isprint(g_result.input_chr);
	if (g_presult.input_str1)
		ft_putstr_isprint(g_result.input_str1);
	if (g_presult.input_str2)
		ft_putstr_isprint(g_result.input_str2);
	printf("\n");
}

static void	ft_print_output_user(void)
{
	printf("%s%s", OUTPUT, USER);
	if (g_presult.output_int)
		printf("%s%i%s ", DM, g_result.user_int, X);
	if (g_presult.output_sizet)
		printf("%s%zu%s ", DM, g_result.user_sizet, X);
	if (g_presult.output_str)
		ft_putstr_isprint(g_result.user_str);
}

static void	ft_print_output_libc(void)
{
	printf("\n\t\t   %s", LIBC);
	if (g_presult.output_int)
		printf("%s%i%s ", DM, g_result.libc_int, X);
	if (g_presult.output_sizet)
		printf("%s%zu%s ", DM, g_result.libc_sizet, X);
	if (g_presult.output_str)
		ft_putstr_isprint(g_result.libc_str);
}

static void	ft_print_output(bool libc)
{
	ft_print_output_user();
	if (libc)
		ft_print_output_libc();
}

void	ft_print_result(bool libc)
{
	printf("%s%s", TEST, KO);
	ft_print_intput();
	ft_print_output(libc);
	printf("\n");
}

void	ft_reset_presult(void)
{
	g_presult.input_int = false;
	g_presult.input_sizet = false;
	g_presult.input_chr = false;
	g_presult.input_str1 = false;
	g_presult.input_str2 = false;
	g_presult.output_int = false;
	g_presult.output_sizet = false;
	g_presult.output_str = false;
}

void	ft_result_input_int(int intput)
{
	g_result.input_int = intput;
	g_presult.input_int = true;
}

void	ft_result_input_sizet(size_t intput)
{
	g_result.input_sizet = intput;
	g_presult.input_sizet = true;
}

void	ft_result_input_chr(char intput)
{
	g_result.input_chr = intput;
	g_presult.input_chr = true;
}

void	ft_result_input_str(char *str1, char *str2)
{
	if (str1)
	{
		g_result.input_str1 = str1;
		g_presult.input_str1 = true;
	}
	if (str2)
	{
		g_result.input_str2 = str2;
		g_presult.input_str2 = true;
	}
}

void	ft_result_output_int(int user, int libc)
{
	g_result.user_int = user;
	g_result.libc_int = libc;
	g_presult.output_int = true;
}

void	ft_result_output_sizet(size_t user, size_t libc)
{
	g_result.user_sizet = user;
	g_result.libc_sizet = libc;
	g_presult.output_sizet = true;
}

void	ft_result_output_str(char *user, char *libc)
{
	g_result.user_str = user;
	g_result.libc_str = libc;
	g_presult.output_str = true;
}

void	ft_grade(bool success)
{
	if (success)
	{
		printf("%s%s", TEST, OK);
		ft_time_function(PRINT);
	}
	printf("%s%s", GRADE, success ? SUCCESS : FAIL);
}
