/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:51:16 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/16 12:59:42 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			max_except_1(t_number **stack, int f)
{
	t_number		*top;
	int				max;

	top = *stack;
	if ((*stack)->num == f)
		max = (*stack)->next->num;
	else
		max = (*stack)->num;
	while (top->next && top->next != *stack)
	{
		if (top->num != f && top->num > max)
			max = top->num;
		top = top->next;
	}
	if (top->num != f && top->num > max)
		max = top->num;
	return (max);
}

int			max_except_2(t_number **stack, int f, int s)
{
	t_number		*top;
	int				max;

	top = *stack;
	while (top->num == f || top->num == s)
		top = top->next;
	max = top->num;
	top = *stack;
	while (top->next && top->next != *stack)
	{
		if (top->num != f && top->num != s && top->num > max)
			max = top->num;
		top = top->next;
	}
	if (top->num != f && top->num != s && top->num > max)
		max = top->num;
	return (max);
}
