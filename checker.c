/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:54:41 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/16 13:23:19 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_instructions(t_number **stack, t_number **stack2, char *s)
{
	if (!ft_strcmp(s, "sa"))
		return (swap(stack));
	else if (!ft_strcmp(s, "sb"))
		return (swap(stack2));
	else if (!ft_strcmp(s, "ss"))
		return (swap(stack) && swap(stack2));
	else if (!ft_strcmp(s, "pa"))
		return (push_from_to(stack, stack2));
	else if (!ft_strcmp(s, "pb"))
		return (push_from_to(stack2, stack));
	else if (!ft_strcmp(s, "ra"))
		return (rotate(stack));
	else if (!ft_strcmp(s, "rb"))
		return (rotate(stack2));
	else if (!ft_strcmp(s, "rr"))
		return (rotate(stack) && rotate(stack2));
	else if (!ft_strcmp(s, "rra"))
		return (rev_rotate(stack));
	else if (!ft_strcmp(s, "rrb"))
		return (rev_rotate(stack2));
	else if (!ft_strcmp(s, "rrr"))
		return (rev_rotate(stack) && rev_rotate(stack2));
	return (0);
}

static int	read_instructions(t_number **stack, t_number **stack2)
{
	char	*s;

	while (get_next_line(0, &s) > 0)
	{
		if (!ft_strlen(s))
			break ;
		if (!do_instructions(stack, stack2, s))
			return (free_error(stack, stack2, 0));
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_number	*stack;
	t_number	*stack2;

	stack = 0;
	stack2 = 0;
	if (argc == 1)
		return (1);
	while (argc-- > 1)
		if (!create_stack(&stack, *(++argv)))
			return (1);
	if (!read_instructions(&stack, &stack2))
		return (1);
	if (!check_sort(&stack) || stack2)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free_stack(&stack);
	free_stack(&stack2);
	return (0);
}
