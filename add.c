/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:02:55 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/19 10:40:33 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_and_push(t_number **stack, t_number **stack2, int med, t_opt *opt)
{
	if (!do_correct_reverse(stack, stack2, med, opt))
		return (0);
	push_from_to(stack2, stack);
	ft_putstr("pb\n");
	if (opt->display)
		display_stacks(stack, stack2);
	return (1);
}

void		chunk_parse(t_number **stack, t_number **stack2, int chunk, t_opt *opt)
{
	if (chunk == 4)
	{
		count_push(stack, stack2, chunk, 1);
		if (opt->display)
			display_stacks(stack, stack2);
		a_sort4(stack, stack2, opt);
	}
	else if (chunk == 3)
	{
		b_sort3(stack, stack2, opt);
		count_push(stack, stack2, chunk, 1);
		if (opt->display)
			display_stacks(stack, stack2);
	}
	else if (chunk == 2)
	{
		b_sort2(stack, stack2, opt);
		count_push(stack, stack2, chunk, 1);
		if (opt->display)
			display_stacks(stack, stack2);
	}
	else if (chunk == 1)
	{
		count_push(stack, stack2, 1, 1);
		if (opt->display)
			display_stacks(stack, stack2);
	}
}
