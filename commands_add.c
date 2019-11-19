/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:20:28 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/19 14:44:09 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		count_swap(t_number **stack, int count, int st, t_opt *opt)
{
	if (st == 1)
	{
		while (count-- > 0)
		{
			swap(stack);
			ft_putstr_fd("sa\n", opt->fd);
		}
	}
	else if (st == 2)
	{
		while (count-- > 0)
		{
			swap(stack);
			ft_putstr_fd("sb\n", opt->fd);
		}
	}
}

void		count_rotate(t_number **stack, int count, int st, t_opt *opt)
{
	if (st == 1)
	{
		while (count-- > 0)
		{
			rotate(stack);
			ft_putstr_fd("ra\n", opt->fd);
		}
	}
	else if (st == 2)
	{
		while (count-- > 0)
		{
			rotate(stack);
			ft_putstr_fd("rb\n", opt->fd);
		}
	}
}

void		count_rev_rotate(t_number **stack, int count, int st, t_opt *opt)
{
	if (st == 1)
	{
		while (count-- > 0)
		{
			rev_rotate(stack);
			ft_putstr_fd("rra\n", opt->fd);
		}
	}
	else if (st == 2)
	{
		while (count-- > 0)
		{
			rev_rotate(stack);
			ft_putstr_fd("rrb\n", opt->fd);
		}
	}
}
