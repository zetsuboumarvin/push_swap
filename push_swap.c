/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:35:57 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/18 15:54:57 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_min_to_a(t_number **stack, t_number **stack2)
{
	int			min;
	int			count;

	find_min(stack2, &min);
	do_reverse_b(stack2, find_min_way(stack2, min, &count), count);
	count_push(stack, stack2, 1, 1);
}

static void	print_instructions(t_number **stack, t_number **stack2,
								int argc, t_opt *opt)
{
	int			min;
	int			count;

	if (argc == 3)
		dsort2(stack, stack2, 1, opt);
	else if (argc == 4)
		dsort3(stack, stack2, 1, opt);
	else if (argc == 5)
		argc5(stack, stack2, opt);
	else if (argc == 6)
		argc6(stack, stack2, opt);
	else if (argc == 7)
		argc7(stack, stack2, opt);
	else
	{
		q_sort(stack, stack2, opt);
		if (*stack2)
			push_min_to_a(stack, stack2);
		while (*stack2)
			q_sort_b(stack, stack2);
		find_min(stack, &min);
		do_reverse_a(stack, find_min_way(stack, min, &count), count);
	}
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
	print_instructions(&stack, &stack2, quantity, opt);
	free_stack(&stack);
	free_stack(&stack2);
	return (0);
}
