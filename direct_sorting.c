/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:25:49 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/19 18:42:23 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		dsort2(t_number **stack, t_number **stack2, int first, t_opt *opt)
{
	t_number		*top;

	top = *stack;
	if (top->num > top->next->num)
	{
		if (first == 1)
		{
			swap(stack);
			ft_putstr_fd("sa\n", opt->fd);
		}
		else
		{
			swap(stack2);
			ft_putstr_fd("sb\n", opt->fd);
		}
		if (opt->display)
			display_stacks(stack, stack2);
	}
}

void		dsort3(t_number **stack, t_number **stack2, int first, t_opt *opt)
{
	t_number	*top;
	int			a;
	int			b;
	int			c;

	top = first == 1 ? *stack : *stack2;
	a = top->num;
	b = top->next->num;
	c = top->next->next->num;
	if (c > a && c > b)
		dsort2(stack, stack2, first, opt);
	else if (b > a && b > c)
	{
		first == 1 ? count_rev_rotate(stack, 1, first, opt) : count_rev_rotate(stack2, 1, first, opt);
		if (opt->display)
			display_stacks(stack, stack2);
		dsort2(stack, stack2, first, opt);
	}
	else if (a > b && a > c)
	{
		first == 1 ? count_rotate(stack, 1, first, opt) : count_rotate(stack2, 1, first, opt);
		if (opt->display)
			display_stacks(stack, stack2);
		dsort2(stack, stack2, first, opt);
	}
}
