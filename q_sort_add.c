/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:00:05 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/15 10:38:46 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			count_length_in(t_number **stack, int start, int end)
{
	int			count;
	t_number	*top;

	count = 0;
	top = *stack;
	while (top && top->num != start)
		top = top->next;
	while (top->next && top->num != end)
	{
		top = top->next;
		count++;
	}
	count++;
	return (count);
}

void			find_3_max(t_number **stack, int *f, int *s, int *t)
{
	t_number	*top;
	int			max;

	find_max(stack, f);
	top = *stack;
	if ((*stack)->num == *f)
		max = (*stack)->next->num;
	else
		max = (*stack)->num;
	while (top->next && top->next != *stack)
	{
		if (top->num != *f && top->num > max)
			max = top->num;
		top = top->next;
	}
	if (top->num != *f && top->num > max)
		max = top->num;
	*s = max;
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
}

int				find_4_max(t_number **stack, int *f, int *s, int *t)
{
	t_number	*top;
	int			max;

	find_max(stack, f);
	top = *stack;
	if ((*stack)->num == *f)
		max = (*stack)->next->num;
	else
		max = (*stack)->num;
	while (top->next && top->next != *stack)
	{
		if (top->num != *f && top->num > max)
			max = top->num;
		top = top->next;
	}
	if (top->num != *f && top->num > max)
		max = top->num;
	*s = max;
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
	//
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
	int			f;
	int			s;
	int			t;
	int			four;
	int			best;
	int			count1;
	int			count2;

	n = count_length(stack2);

/*
	if (n > 3)
	{
		find_3_max(stack2, &f, &s, &t);
		best = find_bestof3(stack2, f, s, t);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		if (best == f)
			best = find_bestof2(stack2, s, t);
		else if (best == s)
			best = find_bestof2(stack2, f, t);
		else
			best = find_bestof2(stack2, f, s);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		find_max(stack2, &best);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		a_sort3(stack, 1);
	}
*/
/*
	if (n > 4 && n > 100)
	{
		four = find_4_max(stack2, &f, &s, &t);
		best = find_bestof3(stack2, f, s, t);
		find_min_way(stack2, best, &count1);
		find_min_way(stack2, four, &count2);
		if (count2 < count1)
			best = four;
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");

		find_3_max(stack2, &f, &s, &t);
		best = find_bestof3(stack2, f, s, t);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		if (best == f)
			best = find_bestof2(stack2, s, t);
		else if (best == s)
			best = find_bestof2(stack2, f, t);
		else
			best = find_bestof2(stack2, f, s);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		find_max(stack2, &best);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		a_sort4(stack);
	}
	*/
	// TEST
	if (n > 4 && n > 100)
	{
		four = find_4_max(stack2, &f, &s, &t);
		best = find_bestof3(stack2, f, s, t);
		find_min_way(stack2, best, &count1);
		find_min_way(stack2, four, &count2);
		if (count2 < count1)
			best = four;
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");

		find_3_max(stack2, &f, &s, &t);
		best = find_bestof3(stack2, f, s, t);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		if (best == f)
			best = find_bestof2(stack2, s, t);
		else if (best == s)
			best = find_bestof2(stack2, f, t);
		else
			best = find_bestof2(stack2, f, s);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		find_max(stack2, &best);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		a_sort4(stack);
	}


	else if (n > 4 && n < 100)
	{
		find_3_max(stack2, &f, &s, &t);
		best = find_bestof3(stack2, f, s, t);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		if (best == f)
			best = find_bestof2(stack2, s, t);
		else if (best == s)
			best = find_bestof2(stack2, f, t);
		else
			best = find_bestof2(stack2, f, s);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		find_max(stack2, &best);
		do_reverse_b(stack2, find_min_way(stack2, best, &n), n, 1);
		push_from_to(stack, stack2);
		ft_putstr("pa\n");
		a_sort3(stack, 1);
	}
	else if (n == 4)
	{
		b_dsort4(stack2);
		while (*stack2)
		{
			push_from_to(stack, stack2);
			ft_putstr("pa\n");
		}
	}
	// TEST
	else if (n == 3)
	{
		b_dsort3(stack2);
		while (*stack2)
		{
			push_from_to(stack, stack2);
			ft_putstr("pa\n");
		}
	}
	else if (n == 2)
	{
		b_sort2(stack2, 2);
		while (*stack2)
		{
			push_from_to(stack, stack2);
			ft_putstr("pa\n");
		}
	}
	else
	{
		push_from_to(stack, stack2);
			ft_putstr("pa\n");
	}
}
