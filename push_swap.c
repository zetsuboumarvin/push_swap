/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:30:34 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/15 10:43:46 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_instructions(t_number **stack, t_number **stack2, int argc)
{
	if (argc == 3)
		dsort2(stack, 1);
	else if (argc == 4)
		dsort3(stack, 1);
	else if (argc == 5)
		argc5(stack, stack2);
	else if (argc == 6)
		argc6(stack, stack2);
	else if (argc == 7)
		argc7(stack, stack2);
	else
	{
		q_sort(stack, stack2);
		while (*stack2)
			q_sort_b(stack, stack2);
	}
}

int			main(int argc, char **argv)
{
	t_number	*stack;
	t_number	*stack2;
	int			quantity;

	stack = 0;
	stack2 = 0;
	quantity = argc;
	if (argc == 1)
		return (1);
	while (argc-- > 1)
		if (!create_stack(&stack, *(++argv)))
			return (1);
	if (check_sort(&stack))
		return (0);
	print_instructions(&stack, &stack2, quantity);
	free_stack(&stack);
	free_stack(&stack2);
	return (0);
}
