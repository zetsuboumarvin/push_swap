/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:00:05 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/18 15:55:25 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			q_sort_b(t_number **stack, t_number **stack2)
{
	int			count_b;
	int			count_a;
	int			best;
	int			best_num;
	t_number	*top;

	top = *stack2;
	best_num = (*stack2)->num;
	best = count_length(stack2);
	while (top->next)
	{
		find_min_way(stack2, top->num, &count_b);
		find_min_way_a(stack, top->num, &count_a);
		if (count_a + count_b <= best)
		{
			best = count_a + count_b;
			best_num = top->num;
		}
		if (top->next == *stack2)
			break;
		top = top->next;
	}
	do_reverse_b(stack2, find_min_way(stack2, best_num, &count_b), count_b);
	do_reverse_a(stack, find_min_way_a(stack, best_num, &count_a), count_a);
	count_push(stack, stack2, 1, 1);
}
