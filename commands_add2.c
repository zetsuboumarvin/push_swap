/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_add2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:22:15 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/16 13:22:23 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		double_rotate(t_number **stack, t_number **stack2, int count)
{
	while (count-- > 0)
	{
		rotate(stack);
		rotate(stack2);
		ft_putstr("rr\n");
	}
}

void		double_rev_rotate(t_number **stack, t_number **stack2, int count)
{
	while (count-- > 0)
	{
		rev_rotate(stack);
		rev_rotate(stack2);
		ft_putstr("rrr\n");
	}
}
