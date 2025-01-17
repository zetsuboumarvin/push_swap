/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:23:29 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 11:45:42 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					find_min_way(t_number **stack, int num, int *count)
{
	t_number	*top;
	int			t_count;
	int			length;

	top = *stack;
	t_count = 0;
	length = count_length(stack);
	while (top->num != num)
	{
		t_count++;
		top = top->next;
	}
	if (t_count > length / 2)
	{
		*count = length - t_count;
		return (-1);
	}
	else
	{
		*count = t_count;
		return (1);
	}
}

static int			get_count(int *count, int t_count, int length)
{
	if (t_count > length / 2)
	{
		*count = length - t_count;
		return (-1);
	}
	else
	{
		*count = t_count;
		return (1);
	}
}

int					find_min_way_a(t_number **stack, int num, int *count)
{
	t_number	*top;
	int			t_count;
	int			length;
	int			min;

	top = *stack;
	t_count = 0;
	length = count_length(stack);
	find_min(stack, &min);
	if (num < min)
		return (find_min_way(stack, min, count));
	while (top->next && top->next != *stack)
	{
		t_count++;
		if (top->num < num && top->next->num > num)
			break ;
		top = top->next;
	}
	if (top->next && top->next == *stack &&
		top->num < num && top->next->num > num)
		t_count++;
	return (get_count(count, t_count, length));
}

void				find_min(t_number **stack, int *tmin)
{
	int			min;
	t_number	*top;

	if (!(*stack))
		return ;
	top = *stack;
	min = top->num;
	while (top->next && top->next != *stack)
	{
		if (top->num < min)
			min = top->num;
		top = top->next;
	}
	if (top->num < min)
		min = top->num;
	*tmin = min;
}

int					count_length(t_number **stack)
{
	int			count;
	t_number	*top;

	count = 0;
	top = *stack;
	if (!*stack)
		return (0);
	while (top->next && top->next != *stack)
	{
		count++;
		top = top->next;
	}
	return (++count);
}
