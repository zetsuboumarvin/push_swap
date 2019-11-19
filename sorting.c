/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:19:47 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/19 11:03:49 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_reverse_a_p(t_number **stack, t_number **stack2, int direct,
							int count)
{
	if (direct == 1)
	{
		while (count-- > 0)
		{
			rotate(stack);
			ft_putstr("ra\n");
			display_stacks(stack, stack2);
		}
	}
	else
	{
		while (count-- > 0)
		{
			rev_rotate(stack);
			ft_putstr("rra\n");
			display_stacks(stack, stack2);
		}
	}
}

void		do_reverse_b_p(t_number **stack, t_number **stack2, int direct,
							int count)
{
	if (direct == 1)
	{
		while (count-- > 0)
		{
			rotate(stack2);
			ft_putstr("rb\n");
			display_stacks(stack, stack2);
		}
	}
	else
	{
		while (count-- > 0)
		{
			rev_rotate(stack2);
			ft_putstr("rrb\n");
			display_stacks(stack, stack2);
		}
	}
}

void		merge(t_number **stack, t_number **stack2, t_opt *opt)
{
	int			min;
	int			count;
	int			max;
	t_number	*temp;

	find_max(stack, &max);
	temp = *stack2;
	while (*stack2 && (*stack2)->next != temp && (*stack2)->num < max)
	{
		if ((*stack2)->num < (*stack)->num)
			count_push(stack, stack2, 1, 1);
		else
			count_rotate(stack, 1, 1);
		if (opt->display)
			display_stacks(stack, stack2);
	}
	if (*stack2 && (*stack2)->num < max)
	{
		if ((*stack2)->num < (*stack)->num)
			count_push(stack, stack2, 1, 1);
		else
			count_rotate(stack, 1, 1);
		if (opt->display)
			display_stacks(stack, stack2);
	}
	find_min(stack, &min);
	if ((*stack)->num != min)
	{
		if (opt->display)
			do_reverse_a_p(stack, stack2, find_min_way(stack, min, &count), count);
		else
			do_reverse_a(stack, find_min_way(stack, min, &count), count);
	}
	while (*stack2)
	{
		count_push(stack, stack2, 1, 1);
		if (opt->display)
			display_stacks(stack, stack2);
	}
	if ((*stack)->num != min)
	{
		if (opt->display)
			do_reverse_a_p(stack, stack2, find_min_way(stack, min, &count), count);
		else
			do_reverse_a(stack, find_min_way(stack, min, &count), count);
	}
}
