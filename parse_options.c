/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:29:34 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/19 11:05:30 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			create_opt(t_opt **opt)
{
	*opt = (t_opt*)malloc(sizeof(t_opt));
	if (!*opt)
		return (0);
	(*opt)->help = 0;
	(*opt)->color = 0;
	(*opt)->display = 0;
	return (1);
}

int			parse_options(t_opt *opt, char *s)
{
	if (s[0] != '-' || ft_strlen(s) > 4)
		return (0);
	if (ft_strchr(s, 'h'))
		opt->help = 1;
	if (ft_strchr(s, 'v'))
		opt->display = 1;
	if (ft_strchr(s, 'c'))
		opt->color = 1;
	if (opt->help || opt->display || opt->color)
		return (1);
	return (0);
}

void		display_stacks(t_number **stack, t_number **stack2)
{
	t_number	*top_a;
	t_number	*top_b;

	top_a = *stack;
	top_b = *stack2;
	ft_printf("    A        B    \n");
	while (top_a || top_b)
	{
		if (top_a && top_b)
			ft_printf("%-9d%-9d\n", top_a->num, top_b->num);
		else if (top_a)
			ft_printf("%-9d\n", top_a->num);
		else if (top_b)
			ft_printf("         %-9d\n", top_b->num);
		if (top_a && top_a->next && top_a->next != *stack)
			top_a = top_a->next;
		else
			top_a = 0;
		if (top_b && top_b->next && top_b->next != *stack2)
			top_b = top_b->next;
		else
			top_b = 0;
	}
	ft_printf("------------------\n\n");
}

void		display_stacks_color(t_number **stack, t_number **stack2, int color)
{
	t_number	*top_a;
	t_number	*top_b;
	char		*col;

	top_a = *stack;
	top_b = *stack2;
	if (color == 0)
		col = ANSI_COLOR_MAGENTA;
	else if (color == 1)
		col = ANSI_COLOR_RED;
	else if (color == 2)
		col = ANSI_COLOR_YELLOW;
	else
		col = ANSI_COLOR_GREEN;
	ft_printf("%s    A        B    {eoc}\n", col);
	while (top_a || top_b)
	{
		if (top_a && top_b)
			ft_printf("%s%-9d%-9d{eoc}\n", col, top_a->num, top_b->num);
		else if (top_a)
			ft_printf("%s%-9d{eoc}\n", col, top_a->num);
		else if (top_b)
			ft_printf("%s         %-9d{eoc}\n", col, top_b->num);
		if (top_a && top_a->next && top_a->next != *stack)
			top_a = top_a->next;
		else
			top_a = 0;
		if (top_b && top_b->next && top_b->next != *stack2)
			top_b = top_b->next;
		else
			top_b = 0;
	}
	ft_printf("%s------------------{eoc}\n\n", col);
}
