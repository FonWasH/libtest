/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 07:59:30 by juperez           #+#    #+#             */
/*   Updated: 2024/03/29 15:21:30 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_bonus(bool title, bool force)
{
	if (title)
		system(TITLE);
	(void)force;
	printf("\nBONUS - WIP\n");
}
