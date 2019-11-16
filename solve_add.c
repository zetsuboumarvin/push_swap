/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:23:32 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/16 13:28:27 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_reverse_a(t_number **stack, int direct, int count, int print)
{
	if (direct == 1)
	{
		while (count-- > 0)
		{
			rotate(stack);
			if (print)
				ft_putstr("ra\n");
		}
	}
	else
	{
		while (count-- > 0)
		{
			rev_rotate(stack);
			if (print)
				ft_putstr("rra\n");
		}
	}
}

void		do_reverse_b(t_number **stack, int direct, int count, int print)
{
	if (direct == 1)
	{
		while (count-- > 0)
		{
			rotate(stack);
			if (print)
				ft_putstr("rb\n");
		}
	}
	else
	{
		while (count-- > 0)
		{
			rev_rotate(stack);
			if (print)
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

int			check_sort_rev(t_number **head)
{
	t_number	*temp;

	if (head)
	{
		temp = *head;
		if (!(*head) || !(temp->next))
			return (1);
		while (temp->next && temp->next != *head)
		{
			if (temp->num < temp->next->num)
				return (0);
			temp = temp->next;
		}
		return (1);
	}
	return (0);
}
