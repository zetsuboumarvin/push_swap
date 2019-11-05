/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:30:34 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/05 18:38:33 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_minmax(t_number **stack, t_number **stack2,
						int max,  int *minmax)
{
	while ((*stack2)->num != max)
	{
		rotate(stack2);
		ft_putstr("rb\n");
	}
	rotate(stack2);
	ft_putstr("rb\n");
	*minmax = (*stack)->num;
	push_from_to(stack2, stack);
	ft_putstr("pb\n");
}

static void	find_lower(t_number **stack, t_number **stack2)
{
	while ((*stack)->num > (*stack2)->num)
	{
		rotate(stack2);
		ft_putstr("rb\n");
	}
	push_from_to(stack2, stack);
	ft_putstr("pb\n");
}

static void	find_higher(t_number **stack, t_number **stack2)
{
	int		count;

	count = 0;
	while ((*stack)->num < (*stack2)->num)
	{
		rev_rotate(stack2);
		count++;
	}
	rotate(stack2);
	push_from_to(stack2, stack);
	while (count-- > 1)
		ft_putstr("rrb\n");
	ft_putstr("pb\n");
}

static void	print_instructions(t_number **stack, t_number **stack2)
{
	int		min;
	int		max;

	max = min = (*stack)->num;
	while (*stack)
	{
		if (!(*stack2) || (*stack)->num < (*stack2)->num)
		{
			if (!(*stack)->next)
				return ;
			push_from_to(stack2, stack);
			ft_putstr("pb\n");
		}
		else
		{
			if ((*stack)->num > max)
				do_minmax(stack, stack2, max, &max);
			else if ((*stack)->num < min)
				do_minmax(stack, stack2, max, &min);
			else if ((*stack)->num > (*stack2)->num)
				find_lower(stack, stack2);
			else if ((*stack)->num < (*stack2)->num)
				find_higher(stack, stack2);
		}
	}
}

int			main(int argc, char **argv)
{
	t_number	*stack;
	t_number	*stack2;

	stack = 0;
	stack2 = 0;
	if (argc == 1)
		return (1);
	while (argc-- > 1)
		if (!create_stack(&stack, *(++argv)))
			return (1);
	if (check_sort(&stack))
		return (0);
	print_instructions(&stack, &stack2);
	free(stack);
	free(stack2);
	return (0);
}
