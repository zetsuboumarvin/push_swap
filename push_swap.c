/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:35:57 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/19 10:53:57 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_min_to_a(t_number **stack, t_number **stack2, t_opt *opt)
{
	int			min;
	int			count;

	find_min(stack2, &min);
	if (opt->display)
		do_reverse_b_p(stack, stack2, find_min_way(stack2, min, &count), count);
	else
		do_reverse_b(stack2, find_min_way(stack2, min, &count), count);
	count_push(stack, stack2, 1, 1);
	if (opt->display)
		display_stacks(stack, stack2);
}

static void	print_instructions(t_number **stack, t_number **stack2, t_opt *opt)
{
	int			min;
	int			count;

	q_sort(stack, stack2, opt);
	if (opt->color)
		display_stacks_color(stack, stack2, 1);
	if (*stack2)
		push_min_to_a(stack, stack2, opt);
	while (*stack2)
		q_sort_b(stack, stack2, opt);
	if (opt->color)
		display_stacks_color(stack, stack2, 2);
	find_min(stack, &min);
	if (opt->display)
		do_reverse_a_p(stack, stack2, find_min_way(stack, min, &count), count);
	else
		do_reverse_a(stack, find_min_way(stack, min, &count), count);
	if (opt->color)
		display_stacks_color(stack, stack2, 3);
}

int			main(int argc, char **argv)
{
	t_number	*stack;
	t_number	*stack2;
	int			quantity;
	t_opt		*opt;

	stack = 0;
	stack2 = 0;
	quantity = argc;
	if (!create_opt(&opt) || argc == 1)
		return (1);
	while (argc-- > 1)
		if (!create_stack(&stack, *(++argv), opt))
			return (1);
	if (check_sort(&stack))
		return (0);
	print_instructions(&stack, &stack2, opt);
	free_stack(&stack);
	free_stack(&stack2);
	return (0);
}
