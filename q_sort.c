/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:43:24 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/16 13:24:33 by jflorent         ###   ########.fr       */
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
	while (top1->prev && top2->prev != *stack && top2->num > med)
		top2 = top2->prev;
	if (top2->num <= med)
		*num2 = top2->num;
	else
		return (0);
	return (1);
}

void		do_correct_reverse(t_number **stack, int num1, int num2, int st)
{
	int			count1;
	int			count2;
	int			direct1;
	int			direct2;

	direct1 = find_min_way(stack, num1, &count1);
	direct2 = find_min_way(stack, num2, &count2);
	if (count1 < count2)
		st == 1 ? do_reverse_a(stack, direct1, count1, 1) :
					do_reverse_b(stack, direct1, count1, 1);
	else
		st == 1 ? do_reverse_a(stack, direct2, count2, 1) :
					do_reverse_b(stack, direct2, count2, 1);
}

static int	init_sort_a(t_number **stack, int n)
{
	if (n == 4)
		a_dsort4(stack);
	if (n == 3)
		dsort3(stack, 1);
	else if (n == 2)
		dsort2(stack, 1);
	return ((*stack)->num);
}

int			q_sort(t_number **stack, t_number **stack2)
{
	int		med;
	int		n;
	int		chunk;

	chunk = 0;
	n = 0;
	if ((n = count_length(stack)) < 5)
		return (init_sort_a(stack, n));
	med = get_medium(stack, get_last(stack));
	while (find_and_push(stack, stack2, med, 1))
		chunk++;
	q_sort(stack, stack2);
	chunk_parse(stack, stack2, chunk);
	return ((*stack)->num);
}
