/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:00:05 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 12:04:12 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		do_rev_and_push(t_number **stack, t_number **stack2,
								int best_num, t_opt *opt)
{
	int			count_a;
	int			count_b;

	opt->direct = find_min_way(stack2, best_num, &count_b);
	opt->count = count_b;
	do_reverse_b(stack, stack2, opt);
	opt->direct = find_min_way_a(stack, best_num, &count_a);
	opt->count = count_a;
	do_reverse_a(stack, stack2, opt);
	opt->count = 1;
	opt->st = 1;
	count_push(stack, stack2, opt);
}

void			q_sort_b(t_number **stack, t_number **stack2, t_opt *opt)
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
			break ;
		top = top->next;
	}
	do_rev_and_push(stack, stack2, best_num, opt);
}

void			s_sort(t_number **stack, t_number **stack2, t_opt *opt)
{
	int			n;

	while ((n = count_length(stack)) > 3)
	{
		push_from_to(stack2, stack);
		ft_putstr_fd("pb\n", opt->fd);
		if (opt->display)
			display_stacks(stack, stack2);
	}
	if (opt->color)
		display_stacks_color(stack, stack2, 0);
	init_sort_a(stack, stack2, n, opt);
	if ((n = count_length(stack2)) < 4)
		do_sort_b(stack, stack2, opt, n);
}
