/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:01:09 by clianne           #+#    #+#             */
/*   Updated: 2019/10/12 13:17:18 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** long arithmetic: cmp long arithmetic
*/

int		do_la_cmp(int *la_int1, int *la_int2)
{
	int	idx;
	int	c;
	int	sign;

	if (la_int1[LA_MAXLEN] != la_int2[LA_MAXLEN])
		return (la_int2[LA_MAXLEN] - la_int1[LA_MAXLEN]);
	idx = 0;
	sign = la_int1[LA_MAXLEN];
	c = LA_MAXLEN - 1;
	while (idx >= 0)
	{
		if ((sign == 0 && la_int1 < la_int2) ||
			(sign == 1 && la_int1 > la_int2))
			return (-1);
		else if ((sign == 0 && la_int1 > la_int2) ||
			(sign == 1 && la_int1 < la_int2))
			return (1);
		idx--;
	}
	return (0);
}
