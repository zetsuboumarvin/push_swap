/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:43:24 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/19 18:54:53 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_last(t_number **stack)
{
	t_number		*top;

	top = *stack;
	while (top->next != *stack)
		top = top->next;
	return (top->num);
}

int			find_nums(t_number **stack, int *num1, int *num2, int med)
{
	t_number	*top1;
	t_number	*top2;

	top1 = *stack;
	top2 = *stack;
	while (top1->next && top1->next != *stack && top1->num > med)
		top1 = top1->next;
	if (top1->num <= med)
		*num1 = top1->num;
	else
		return (0);
	while (top2->prev && top2->prev != *stack && top2->num > med)
		top2 = top2->prev;
	if (top2->num <= med)
		*num2 = top2->num;
	else
		return (0);
	return (1);
}

int			do_correct_reverse(t_number **stack, t_number **stack2, int med, t_opt *opt)
{
	int			count1;
	int			count2;
	int			num1;
	int			num2;

	if (!find_nums(stack, &num1, &num2, med))
		return (0);
	find_min_way(stack, num1, &count1);
	find_min_way(stack, num2, &count2);
	opt->direct = count1 < count2 ? find_min_way(stack, num1, &count1) : find_min_way(stack, num2, &count2);
	if (count1 < count2)
	{
		opt->count = count1;
		do_reverse_a(stack, stack2, opt);
	}
	else
	{
		opt->count = count2;
		do_reverse_a(stack, stack2, opt);
	}
	return (1);
}

static int	init_sort_a(t_number **stack, t_number **stack2, int n, t_opt *opt)
{
	if (n == 3)
		dsort3(stack, stack2, 1, opt);
	else if (n == 2)
		dsort2(stack, stack2, 1, opt);
	return ((*stack)->num);
}

int			q_sort(t_number **stack, t_number **stack2, t_opt *opt)
{
	int		med;
	int		n;
	int		chunk;

	chunk = 0;
	n = 0;
	if ((n = count_length(stack)) < 4)
	{
		if (opt->color)
			display_stacks_color(stack, stack2, 0);
		return (init_sort_a(stack, stack2, n, opt));
	}
	med = get_medium(stack, get_last(stack));
	while (find_and_push(stack, stack2, med, opt))
		chunk++;
	//THINK
	if (chunk < 4)
		do_sort_b(stack, stack2, opt, chunk);
	//
	q_sort(stack, stack2, opt);
	return ((*stack)->num);
}
