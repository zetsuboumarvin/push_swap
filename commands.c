/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:42:46 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/19 15:42:21 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			swap(t_number **stack)
{
	t_number	*first;
	t_number	*second;

	if (stack && *stack && (*stack)->next)
	{
		first = pop(stack);
		second = pop(stack);
		push(stack, first);
		push(stack, second);
	}
	return (1);
}

int			push_from_to(t_number **consumer, t_number **producer)
{
	t_number	*node;

	node = pop(producer);
	if (!node)
		return (1);
	push(consumer, node);
	return (1);
}

void		count_push(t_number **cons, t_number **prod, t_opt *opt)
{
	t_number	*node;

	while (opt->count-- > 0)
	{
		node = pop(prod);
		if (!node)
			return ;
		push(cons, node);
		if (opt->st == 1)
			ft_putstr_fd("pa\n", opt->fd);
		else if (opt->st == 2)
			ft_putstr_fd("pb\n", opt->fd);
		if (opt->display && opt->st == 1)
			display_stacks(cons, prod);
		else if (opt->display && opt->st == 2)
			display_stacks(prod, cons);
	}
}

int			rotate(t_number **stack)
{
	t_number	*first;

	if (!(*stack) || !((*stack)->next))
		return (1);
	first = pop(stack);
	push_behind(stack, first);
	return (1);
}

int			rev_rotate(t_number **stack)
{
	if (!(*stack) || !((*stack)->next))
		return (1);
	*stack = (*stack)->prev;
	return (1);
}
