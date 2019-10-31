/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_iarray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:00:50 by clianne           #+#    #+#             */
/*   Updated: 2019/10/26 16:03:06 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** to working wih integer arrays for long arithmetic
*/

void	do_iarray_fill(int *ia, size_t size, int init)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		ia[idx] = init;
		idx++;
	}
}

int		*do_iarray_create(size_t size)
{
	int		*ires;

	if (!(ires = (int *)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	do_iarray_fill(ires, size + 1, 0);
	return (ires);
}

void	do_iarray_del(int **ia)
{
	if (ia && *ia)
	{
		free(*ia);
		*ia = NULL;
	}
}
