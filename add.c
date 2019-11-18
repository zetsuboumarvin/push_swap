/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:02:55 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/18 15:54:08 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_and_push(t_number **stack, t_number **stack2, int med, int st)
{
	int			num1;
	int			num2;

	if (!find_nums(stack, &num1, &num2, med))
		return (0);
	do_correct_reverse(stack, num1, num2, st);
	push_from_to(stack2, stack);
	st == 1 ? ft_putstr("pb\n") : ft_putstr("pa\n");
	return (1);
}

void		chunk_parse(t_number **stack, t_number **stack2, int chunk, t_opt *opt)
{
	if (chunk == 4)
	{
		count_push(stack, stack2, chunk, 1);
		a_sort4(stack, stack2, opt);
	}
	else if (chunk == 3)
	{
		b_sort3(stack2, 2);
		count_push(stack, stack2, chunk, 1);
	}
	else if (chunk == 2)
	{
		b_sort2(stack2, 2);
		count_push(stack, stack2, chunk, 1);
	}
	else if (chunk == 1)
		count_push(stack, stack2, 1, 1);
}

void		min_sort_b(t_number **stack, t_number **stack2, int n)
{
	if (n == 4)
	{
		b_dsort4(stack2);
		while (*stack2)
			count_push(stack, stack2, 1, 1);
	}
	else if (n == 3)
	{
		b_dsort3(stack2);
		while (*stack2)
			count_push(stack, stack2, 1, 1);
	}
	else if (n == 2)
	{
		b_sort2(stack2, 2);
		while (*stack2)
			count_push(stack, stack2, 1, 1);
	}
	else
		count_push(stack, stack2, 1, 1);
}
