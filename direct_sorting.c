/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:25:49 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/18 16:09:50 by jflorent         ###   ########.fr       */
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
			ft_putstr("sa\n");
		}
		else
		{
			swap(stack2);
			ft_putstr("sb\n");
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
		first == 1 ? count_rev_rotate(stack, 1, first) : count_rev_rotate(stack2, 1, first);
		if (opt->display)
			display_stacks(stack, stack2);
		dsort2(stack, stack2, first, opt);
	}
	else if (a > b && a > c)
	{
		first == 1 ? count_rotate(stack, 1, first) : count_rotate(stack2, 1, first);
		if (opt->display)
			display_stacks(stack, stack2);
		dsort2(stack, stack2, first, opt);
	}
}

void		b_sort2(t_number **stack, int st)
{
	t_number		*top;

	top = *stack;
	if (top->num < top->next->num)
	{
		swap(stack);
		st == 1 ? ft_putstr("sa\n") : ft_putstr("sb\n");
	}
}

void		b_sort3(t_number **stack, int st)
{
	t_number	*top;
	int			a;
	int			b;
	int			c;

	top = *stack;
	a = top->num;
	b = top->next->num;
	c = top->next->next->num;
	if (c < a && c < b)
		b_sort2(stack, st);
	else if (b < a && b < c)
	{
		count_rotate(stack, 1, st);
		swap(stack);
		st == 1 ? ft_putstr("sa\n") : ft_putstr("sb\n");
		count_rev_rotate(stack, 1, st);
		b_sort2(stack, st);
	}
	else if (a < b && a < c)
	{
		swap(stack);
		st == 1 ? ft_putstr("sa\n") : ft_putstr("sb\n");
		count_rotate(stack, 1, st);
		swap(stack);
		st == 1 ? ft_putstr("sa\n") : ft_putstr("sb\n");
		count_rev_rotate(stack, 1, st);
		b_sort2(stack, st);
	}
}
