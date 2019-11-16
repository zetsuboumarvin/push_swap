/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:02:55 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/16 13:21:11 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_and_push(t_number **stack, t_number **stack2, int med, int st)
{
	int			num1;
	int			num2;

	if (!find_nums(stack, &num1, &num2, med))
		return (0);
	do_correct_reverse(stack, num1, num2, st);
	push_from_to(stack2, stack);
	st == 1 ? ft_putstr("pb\n") : ft_putstr("pa\n");
	return (1);
}

void		chunk_parse(t_number **stack, t_number **stack2, int chunk)
{
	if (chunk == 4)
	{
		count_push(stack, stack2, chunk, 1);
		a_sort4(stack);
	}
	else if (chunk == 3)
	{
		b_sort3(stack2, 2);
		count_push(stack, stack2, chunk, 1);
	}
	else if (chunk == 2)
	{
		b_sort2(stack2, 2);
		count_push(stack, stack2, chunk, 1);
	}
	else if (chunk == 1)
		count_push(stack, stack2, 1, 1);
}

void		min_sort_b(t_number **stack, t_number **stack2, int n)
{
	if (n == 4)
	{
		b_dsort4(stack2);
		while (*stack2)
			count_push(stack, stack2, 1, 1);
	}
	else if (n == 3)
	{
		b_dsort3(stack2);
		while (*stack2)
			count_push(stack, stack2, 1, 1);
	}
	else if (n == 2)
	{
		b_sort2(stack2, 2);
		while (*stack2)
			count_push(stack, stack2, 1, 1);
	}
	else
		count_push(stack, stack2, 1, 1);
}

void		find_and_push_3(t_number **stack, t_number **stack2)
{
	int			f;
	int			s;
	int			t;
	int			best;
	int			n;

	find_3_max(stack2, &f, &s, &t);
	best = find_bestof3(stack2, f, s, t);
	do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
	count_push(stack, stack2, 1, 1);
	if (best == f)
		best = find_bestof2(stack2, s, t);
	else if (best == s)
		best = find_bestof2(stack2, f, t);
	else
		best = find_bestof2(stack2, f, s);
	do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
	count_push(stack, stack2, 1, 1);
	find_max(stack2, &best);
	do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
	count_push(stack, stack2, 1, 1);
}

void		find_and_push_4(t_number **stack, t_number **stack2)
{
	int			f;
	int			s;
	int			t;
	int			best;
	int			four;

	four = find_4_max(stack2, &f, &s, &t);
	best = find_bestof3(stack2, f, s, t);
	find_min_way(stack2, best, &f);
	find_min_way(stack2, four, &s);
	if (s < f)
		best = four;
	do_reverse_b(stack2, find_min_way(stack2, best, &f), f, 1);
	count_push(stack, stack2, 1, 1);
	find_and_push_3(stack, stack2);
}
