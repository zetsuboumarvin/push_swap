/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:19:47 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/13 11:58:43 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		merge(t_number **stack, t_number **stack2)
{
	int			min;
	int			count;
	int			max;
	t_number	*temp;

	find_max(stack, &max);
	temp = *stack2;
	while (*stack2 && (*stack2)->next != temp && (*stack2)->num < max)
	{
		if ((*stack2)->num < (*stack)->num)
			count_push(stack, stack2, 1, 1);
		else
			count_rotate(stack, 1, 1);
	}
	if (*stack2 && (*stack2)->num < max)
	{
		if ((*stack2)->num < (*stack)->num)
			count_push(stack, stack2, 1, 1);
		else
			count_rotate(stack, 1, 1);
	}
	find_min(stack, &min);
	if ((*stack)->num != min)
		do_reverse_a(stack, find_min_way(stack, min, &count), count, 1);
	while (*stack2)
		count_push(stack, stack2, 1, 1);
	if ((*stack)->num != min)
		do_reverse_a(stack, find_min_way(stack, min, &count), count, 1);
}
