/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:23:32 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 10:32:21 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_reverse_a(t_number **stack, t_number **stack2, t_opt *opt)
{
	if (opt->direct == 1)
	{
		while (opt->count-- > 0)
		{
			rotate(stack);
			ft_putstr_fd("ra\n", opt->fd);
			if (opt->display)
				display_stacks(stack, stack2);
		}
	}
	else
	{
		while (opt->count-- > 0)
		{
			rev_rotate(stack);
			ft_putstr_fd("rra\n", opt->fd);
			if (opt->display)
				display_stacks(stack, stack2);
		}
	}
}

void		do_reverse_b(t_number **stack, t_number **stack2, t_opt *opt)
{
	if (opt->direct == 1)
	{
		while (opt->count-- > 0)
		{
			rotate(stack2);
			ft_putstr_fd("rb\n", opt->fd);
			if (opt->display)
				display_stacks(stack, stack2);
		}
	}
	else
	{
		while (opt->count-- > 0)
		{
			rev_rotate(stack2);
			ft_putstr_fd("rrb\n", opt->fd);
			if (opt->display)
				display_stacks(stack, stack2);
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
			top->num <= del->num ? left++ : right++;
			top = top->next;
		}
		top->num <= del->num ? left++ : right++;
		if (left == right || left == right + 1)
			break ;
		del = del->next;
	}
	return (del->num);
}
