/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:37:20 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/18 15:40:16 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		argc5(t_number **stack, t_number **stack2, t_opt *opt)
{
	count_push(stack2, stack, 1, 2);
	if (opt->display)
		display_stacks(stack, stack2);
	count_push(stack2, stack, 1, 2);
	if (opt->display)
		display_stacks(stack, stack2);
	dsort2(stack, stack2, 2, opt);
	dsort2(stack, stack2, 1, opt);
	merge(stack, stack2, opt);
}

void		argc6(t_number **stack, t_number **stack2, t_opt *opt)
{
	count_push(stack2, stack, 1, 2);
	if (opt->display)
		display_stacks(stack, stack2);
	count_push(stack2, stack, 1, 2);
	if (opt->display)
		display_stacks(stack, stack2);
	dsort2(stack, stack2, 2, opt);
	dsort3(stack, stack2, 1, opt);
	merge(stack, stack2, opt);
}

void		argc7(t_number **stack, t_number **stack2, t_opt *opt)
{
	count_push(stack2, stack, 1, 2);
	if (opt->display)
		display_stacks(stack, stack2);
	count_push(stack2, stack, 1, 2);
	if (opt->display)
		display_stacks(stack, stack2);
	count_push(stack2, stack, 1, 2);
	if (opt->display)
		display_stacks(stack, stack2);
	dsort3(stack, stack2, 2, opt);
	dsort3(stack, stack2, 1, opt);
	merge(stack, stack2, opt);
}
