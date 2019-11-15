/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:42:46 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/15 11:11:15 by jflorent         ###   ########.fr       */
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

void		count_push(t_number **cons, t_number **prod, int count, int st)
{
	t_number	*node;

	while (count-- > 0)
	{
		node = pop(prod);
		if (!node)
			return ;
		push(cons, node);
		if (st == 1)
			ft_putstr("pa\n");
		else if (st == 2)
			ft_putstr("pb\n");
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
