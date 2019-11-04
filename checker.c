/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:54:41 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/04 18:01:08 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	create_stack(t_number **stack, char *s)
{
	int				num;

	num = 0;
	if (!parse_string(s, &num))
		return (free_error(stack, 0, 0));
	if (!stack_push_back(stack, num))
		return (free_error(stack, 0, 0));
	return (1);
}

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
}

static int	read_instructions(t_number **stack, t_number **stack2)
{
	int		count;
	char	c;
	char	s[4];

	count = 1;
	c = '0';
	while (count != 0)
	{
		count = 0;
		while (c != '\0' && c != '\n' && count < 4)
		{
			read(0, &c, 1);
			s[count++] = c;
		}
		if (count >= 4 || c == '\0')
			return (free_error(stack, stack2, 0));
		s[count] = '\0';
		if (!do_instructions(stack, stack2, s))
			return (free_error(stack, stack2, 0));
	}
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
	{
		++argv;
		if (!create_stack(stack, *argv))
			return (1);
		if (!read_instructions(&stack, &stack2))
			return (1);
	}
}
