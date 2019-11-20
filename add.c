/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:02:55 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 12:03:44 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_and_push(t_number **stack, t_number **stack2,
						int med, t_opt *opt)
{
	if (!do_correct_reverse(stack, stack2, med, opt))
		return (0);
	push_from_to(stack2, stack);
	ft_putstr_fd("pb\n", opt->fd);
	if (opt->display)
		display_stacks(stack, stack2);
	return (1);
}

static void	do_sort_2_b(t_number **stack, t_number **stack2, t_opt *opt)
{
	if ((*stack2)->num < (*stack2)->next->num)
	{
		count_swap(stack2, 1, 2, opt);
		if (opt->display)
			display_stacks(stack, stack2);
	}
}

static void	do_sort_3_b(t_number **stack, t_number **stack2, t_opt *opt)
{
	int		a;
	int		b;
	int		c;

	a = (*stack2)->num;
	b = (*stack2)->next->num;
	c = (*stack2)->next->next->num;
	if (c < a && c < b)
		do_sort_2_b(stack, stack2, opt);
	else if (b < a && b < c)
	{
		count_rev_rotate(stack2, 1, 2, opt);
		if (opt->display)
			display_stacks(stack, stack2);
		do_sort_2_b(stack, stack2, opt);
	}
	else if (a < b && a < c)
	{
		count_rotate(stack2, 1, 2, opt);
		if (opt->display)
			display_stacks(stack, stack2);
		do_sort_2_b(stack, stack2, opt);
	}
}

void		do_sort_b(t_number **stack, t_number **stack2,
					t_opt *opt, int chunk)
{
	if (chunk == 3)
		do_sort_3_b(stack, stack2, opt);
	else if (chunk == 2)
		do_sort_2_b(stack, stack2, opt);
	while (*stack2)
	{
		push_from_to(stack, stack2);
		ft_putstr_fd("pa\n", opt->fd);
		if (opt->display)
			display_stacks(stack, stack2);
	}
}
