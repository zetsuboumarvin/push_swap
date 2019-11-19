/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:02:55 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/19 18:54:37 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_and_push(t_number **stack, t_number **stack2, int med, t_opt *opt)
{
	if (!do_correct_reverse(stack, stack2, med, opt))
		return (0);
	push_from_to(stack2, stack);
	ft_putstr_fd("pb\n", opt->fd);
	if (opt->display)
		display_stacks(stack, stack2);
	return (1);
}

void		do_sort_b(t_number **stack, t_number **stack2, t_opt *opt, int chunk)
{
	if (chunk == 3)
	{

	}
	else if (chunk == 2)
	{

	}
	else
	{

	}
	while (*stack2)
	{
		push_from_to(stack2, stack);
		ft_putstr_fd("pa\n", opt->fd);
		if (opt->display)
			display_stacks(stack, stack2);
	}
}
