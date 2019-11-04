/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:42:46 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/04 18:04:08 by jflorent         ###   ########.fr       */
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

int			rotate(t_number **stack)
{

}
