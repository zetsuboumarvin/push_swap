/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_sorting_invers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:56:24 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/16 13:29:40 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			b_dsort3(t_number **stack)
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
		b_sort2(stack, 2);
	else if (b < a && b < c)
	{
		count_rev_rotate(stack, 1, 2);
		b_sort2(stack, 2);
	}
	else if (a < b && a < c)
	{
		count_rotate(stack, 1, 2);
		b_sort2(stack, 2);
	}
}

void			b_dsort4(t_number **stack)
{
	t_number	*top;
	int			a;
	int			b;
	int			c;
	int			d;

	top = *stack;
	a = top->num;
	b = top->next->num;
	c = top->next->next->num;
	d = top->next->next->next->num;
	if (a < b && a < c && a < d)
	{
		count_rotate(stack, 1, 2);
		b_sort3(stack, 2);
	}
	else if (b < a && b < c && b < d)
	{
		count_rotate(stack, 2, 2);
		b_sort3(stack, 2);
	}
	else if (c < a && c < b && c < d)
	{
		count_rev_rotate(stack, 1, 2);
		b_sort3(stack, 2);
	}
	else
		b_sort3(stack, 2);
}

void			a_sort3(t_number **stack, int st)
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
		a_sort2(stack, st);
	else if (b > a && b > c)
	{
		count_rotate(stack, 1, st);
		swap(stack);
		st == 1 ? ft_putstr("sa\n") : ft_putstr("sb\n");
		count_rev_rotate(stack, 1, st);
		a_sort2(stack, st);
	}
	else if (a > b && a > c)
	{
		swap(stack);
		st == 1 ? ft_putstr("sa\n") : ft_putstr("sb\n");
		count_rotate(stack, 1, st);
		swap(stack);
		st == 1 ? ft_putstr("sa\n") : ft_putstr("sb\n");
		count_rev_rotate(stack, 1, st);
		a_sort2(stack, st);
	}
}

void			a_sort4(t_number **stack)
{
	t_number	*top;
	int			a;
	int			b;
	int			c;
	int			d;

	top = *stack;
	a = top->num;
	b = top->next->num;
	c = top->next->next->num;
	d = top->next->next->next->num;
	if (a > b && a > c && a > d)
	{
		count_swap(stack, 1, 1);
		count_rotate(stack, 1, 1);
		a_sort3(stack, 1);
		count_rev_rotate(stack, 1, 1);
		a_sort3(stack, 1);
	}
	else if (b > a && b > c && b > d)
	{
		count_rotate(stack, 1, 1);
		a_sort3(stack, 1);
		count_rev_rotate(stack, 1, 1);
		a_sort3(stack, 1);
	}
	else if (c > a && c > b && c > d)
	{
		count_rotate(stack, 1, 1);
		a_sort3(stack, 1);
		count_rev_rotate(stack, 1, 1);
		a_sort3(stack, 1);
	}
	else
		a_sort3(stack, 1);
}

void			a_dsort4(t_number **stack)
{
	t_number	*top;
	int			a;
	int			b;
	int			c;
	int			d;

	top = *stack;
	a = top->num;
	b = top->next->num;
	c = top->next->next->num;
	d = top->next->next->next->num;
	if (a > b && a > c && a > d)
	{
		count_rotate(stack, 1, 1);
		a_sort3(stack, 1);
	}
	else if (b > a && b > c && b > d)
	{
		count_rotate(stack, 2, 1);
		a_sort3(stack, 1);
	}
	else if (c > a && c > b && c > d)
	{
		count_rev_rotate(stack, 1, 1);
		a_sort3(stack, 1);
	}
	else
		a_sort3(stack, 1);
}
