/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:20:28 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/11 12:20:04 by jflorent         ###   ########.fr       */
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

void		double_swap(t_number **stack, t_number **stack2, int count)
{
	while (count-- > 0)
	{
		swap(stack);
		swap(stack2);
		ft_putstr("ss\n");
	}
}

void		count_swap(t_number **stack, int count, int st)
{
	if (st == 1)
	{
		while (count-- > 0)
		{
			swap(stack);
			ft_putstr("sa\n");
		}
	}
	else if (st == 2)
	{
		while (count-- > 0)
		{
			swap(stack);
			ft_putstr("sb\n");
		}
	}
}

void		count_rotate(t_number **stack, int count, int st)
{
	if (st == 1)
	{
		while (count-- > 0)
		{
			rotate(stack);
			ft_putstr("ra\n");
		}
	}
	else if (st == 2)
	{
		while (count-- > 0)
		{
			rotate(stack);
			ft_putstr("rb\n");
		}
	}
}

void		count_rev_rotate(t_number **stack, int count, int st)
{
	if (st == 1)
	{
		while (count-- > 0)
		{
			rev_rotate(stack);
			ft_putstr("rra\n");
		}
	}
	else if (st == 2)
	{
		while (count-- > 0)
		{
			rev_rotate(stack);
			ft_putstr("rrb\n");
		}
	}
}
