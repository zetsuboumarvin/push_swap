/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:25:49 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 10:24:04 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		dsort2(t_number **stack, t_number **stack2, t_opt *opt)
{
	t_number		*top;

	top = *stack;
	if (top->num > top->next->num)
	{
		swap(stack);
		ft_putstr_fd("sa\n", opt->fd);
		if (opt->display)
			display_stacks(stack, stack2);
	}
}

void		dsort3(t_number **stack, t_number **stack2, t_opt *opt)
{
	t_number	*top;
	int			a;
	int			b;
	int			c;

	top = *stack;
	a = top->num;
	b = top->next->num;
	c = top->next->next->num;
	if (c > a && c > b)
		dsort2(stack, stack2, opt);
	else if (b > a && b > c)
	{
		count_rev_rotate(stack, 1, 1, opt);
		if (opt->display)
			display_stacks(stack, stack2);
		dsort2(stack, stack2, opt);
	}
	else if (a > b && a > c)
	{
		count_rotate(stack, 1, 1, opt);
		if (opt->display)
			display_stacks(stack, stack2);
		dsort2(stack, stack2, opt);
	}
}
