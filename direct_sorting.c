/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:25:49 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/13 11:14:27 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		dsort2(t_number **stack, int first)
{
	t_number		*top;

	top = *stack;
	if (top->num > top->next->num)
	{
		swap(stack);
		if (first == 1)
			ft_putstr("sa\n");
		else
			ft_putstr("sb\n");
	}
}

void		dsort3(t_number **stack, int first)
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
		dsort2(stack, first);
	else if (b > a && b > c)
	{
		count_rev_rotate(stack, 1, first);
		dsort2(stack, first);
	}
	else if (a > b && a > c)
	{
		count_rotate(stack, 1 ,first);
		dsort2(stack, first);
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
