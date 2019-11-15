/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:37:20 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/13 08:03:28 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		argc5(t_number **stack, t_number **stack2)
{
	count_push(stack2, stack, 2, 2);
	dsort2(stack2, 2);
	dsort2(stack, 1);
	merge(stack, stack2);
}

void		argc6(t_number **stack, t_number **stack2)
{
	count_push(stack2, stack, 2, 2);
	dsort2(stack2, 2);
	dsort3(stack, 1);
	merge(stack, stack2);
}

void		argc7(t_number **stack, t_number **stack2)
{
	count_push(stack2, stack, 3, 2);
	dsort3(stack2, 2);
	dsort3(stack, 1);
	merge(stack, stack2);
}
