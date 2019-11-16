/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:00:05 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/16 17:22:32 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			find_3_max(t_number **stack, int *f, int *s, int *t)
{
	find_max(stack, f);
	*s = max_except_1(stack, *f);
	*t = max_except_2(stack, *f, *s);
}

int				find_4_max(t_number **stack, int *f, int *s, int *t)
{
	t_number	*top;
	int			max;

	find_max(stack, f);
	*s = max_except_1(stack, *f);
	*t = max_except_2(stack, *f, *s);
	top = *stack;
	while (top->num == *f || top->num == *s || top->num == *t)
		top = top->next;
	max = top->num;
	top = *stack;
	while (top->next && top->next != *stack)
	{
		if (top->num != *f && top->num != *s && top->num != *t &&
			top->num > max)
			max = top->num;
		top = top->next;
	}
	if (top->num != *f && top->num != *s && top->num != *t && top->num > max)
		max = top->num;
	return (max);
}

int				find_bestof3(t_number **stack, int f, int s, int t)
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

int				find_bestof2(t_number **stack, int f, int s)
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

/*
void			q_sort_b(t_number **stack, t_number **stack2)
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
*/

static void		push_min_to_a(t_number **stack, t_number **stack2)
{
	int			min;
	int			count;

	find_min(stack2, &min);
	do_reverse_b(stack2, find_min_way(stack2, min, &count), count, 1);
	count_push(stack, stack2, 1, 1);
}


// NEW VERSION
void			q_sort_b(t_number **stack, t_number **stack2)
{
	int			count_b;
	int			count_a;
	int			best;
	int			best_num;
	t_number	*top;

	push_min_to_a(stack, stack2);
	top = *stack2;
	best_num = (*stack2)->num;
	best = 0;
	find_min_way(stack2, top->num, &count_b);
	find_min_way_a(stack, top->num, &count_a);
	best = count_a + count_b;
	while (top->next != *stack2)
	{
		find_min_way(stack2, top->num, &count_b);
		find_min_way_a(stack, top->num, &count_a);
		if (count_a + count_b <= best)
		{
			best = count_a + count_b;
			best_num = top->num;
		}
		top = top->next;
	}
	find_min_way(stack2, top->num, &count_b);
	find_min_way_a(stack, top->num, &count_a);
	if (count_a + count_b <= best)
		best_num = top->num;
	do_reverse_b(stack2, find_min_way(stack2, best_num, &count_b), count_b, 1);
	do_reverse_a(stack, find_min_way(stack, best_num, &count_a), count_a, 1);
	count_push(stack, stack2, 1, 1);
}
