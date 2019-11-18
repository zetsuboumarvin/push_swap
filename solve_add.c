/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:23:32 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/18 15:41:41 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_reverse_a(t_number **stack, int direct, int count)
{
	if (direct == 1)
	{
		while (count-- > 0)
		{
			rotate(stack);
			ft_putstr("ra\n");
		}
	}
	else
	{
		while (count-- > 0)
		{
			rev_rotate(stack);
			ft_putstr("rra\n");
		}
	}
}

void		do_reverse_b(t_number **stack, int direct, int count)
{
	if (direct == 1)
	{
		while (count-- > 0)
		{
			rotate(stack);
			ft_putstr("rb\n");
		}
	}
	else
	{
		while (count-- > 0)
		{
			rev_rotate(stack);
			ft_putstr("rrb\n");
		}
	}
}

int			get_medium(t_number **stack, int last)
{
	t_number	*top;
	int			left;
	int			right;
	t_number	*del;

	del = *stack;
	while (del->num != last)
	{
		left = 0;
		right = 0;
		top = *stack;
		while (top->num != last)
		{
			if (top->num <= del->num)
				left++;
			else
				right++;
			top = top->next;
		}
		if (left == right || left == right + 1)
			break ;
		del = del->next;
	}
	return (del->num);
}
