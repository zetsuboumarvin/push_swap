/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:00:05 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/16 11:56:51 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			find_3_max(t_number **stack, int *f, int *s, int *t)
{
	t_number	*top;
	int			max;

	find_max(stack, f);
	top = *stack;
	*s = max_except_1(stack, *f);
	while (top->num == *f || top->num == *s)
		top = top->next;
	max = top->num;
	top = *stack;
	while (top->next && top->next != *stack)
	{
		if (top->num != *f && top->num != *s && top->num > max)
			max = top->num;
		top = top->next;
	}
	if (top->num != *f && top->num != *s && top->num > max)
		max = top->num;
	*t = max;
}

int				find_4_max(t_number **stack, int *f, int *s, int *t)
{
	t_number	*top;
	int			max;

	find_max(stack, f);
	top = *stack;
	*s = max_except_1(stack, *f);
	top = *stack;
	while (top->num == *f || top->num == *s)
		top = top->next;
	max = top->num;
	top = *stack;
	while (top->next && top->next != *stack)
	{
		if (top->num != *f && top->num != *s && top->num > max)
			max = top->num;
		top = top->next;
	}
	if (top->num != *f && top->num != *s && top->num > max)
		max = top->num;
	*t = max;
	top = *stack;
	while (top->num == *f || top->num == *s || top->num == *t)
		top = top->next;
	max = top->num;
	top = *stack;
	while (top->next && top->next != *stack)
	{
		if (top->num != *f && top->num != *s &&top->num != *t && top->num > max)
			max = top->num;
		top = top->next;
	}
	if (top->num != *f && top->num != *s && top->num != *t && top->num > max)
		max = top->num;
	return (max);
}

int			find_bestof3(t_number **stack, int f, int s, int t)
{
	int		count_f;
	int		count_s;
	int		count_t;

	find_min_way(stack, f, &count_f);
	find_min_way(stack, s, &count_s);
	find_min_way(stack, t, &count_t);
	if (count_f <= count_s && count_f <= count_t)
		return (f);
	else if (count_s <= count_f && count_s <= count_t)
		return (s);
	else
		return (t);
}

int			find_bestof2(t_number **stack, int f, int s)
{
	int		count_f;
	int		count_s;

	find_min_way(stack, f, &count_f);
	find_min_way(stack, s, &count_s);
	if (count_f <= count_s)
		return (f);
	else
		return (s);
}

void		q_sort_b(t_number **stack, t_number **stack2)
{
	int			n;

	n = count_length(stack2);
	if (n > 4 && n > 100)
	{
		find_and_push_4(stack, stack2);
		a_sort4(stack);
	}
	else if (n > 4 && n < 100)
	{
		find_and_push_3(stack, stack2);
		a_sort3(stack, 1);
	}
	else
		min_sort_b(stack, stack2, n);
}
