/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:35:57 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 16:56:00 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_instructions(t_number **stack, t_number **stack2, t_opt *opt)
{
	int			min;
	int			count;

	q_sort(stack, stack2, opt);
	if (opt->color)
		display_stacks_color(stack, stack2, 1);
	while (*stack2)
		q_sort_b(stack, stack2, opt);
	if (opt->color)
		display_stacks_color(stack, stack2, 2);
	find_min(stack, &min);
	opt->direct = find_min_way(stack, min, &count);
	opt->count = count;
	do_reverse_a(stack, stack2, opt);
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
	{
		free_all(&stack, &stack2, opt);
		return (1);
	}
	while (argc-- > 1)
		if (!create_stack(&stack, *(++argv), opt))
			return (1);
	if (check_sort(&stack))
	{
		free_all(&stack, &stack2, opt);
		return (0);
	}
	print_instructions(&stack, &stack2, opt);
	if (opt->fd != 1)
		close(opt->fd);
	free_all(&stack, &stack2, opt);
	return (0);
}
