/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:54:41 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 16:33:22 by jflorent         ###   ########.fr       */
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

static int	read_instructions(t_number **stack, t_number **stack2, t_opt *opt)
{
	char	*s;

	if (opt->display)
		display_stacks(stack, stack2);
	opt->fd = opt->read_file ? open(opt->file_name, O_RDONLY) : 0;
	if (opt->fd < 0)
		return (0);
	while (get_next_line(opt->fd, &s) > 0)
	{
		if (ft_strlen(s) == 0)
		{
			free(s);
			break ;
		}
		if (!do_instructions(stack, stack2, s))
		{
			free(s);
			return (free_error(stack, stack2, 0, opt));
		}
		if (opt->display)
			display_stacks(stack, stack2);
		free(s);
	}
	return (1);
}

static void	free_all(t_number **stack, t_number **stack2, t_opt *opt)
{
	free_stack(stack);
	free_stack(stack2);
	if (opt->read_file)
	{
		close(opt->fd);
		free(opt->file_name);
	}
	if (opt)
		free(opt);
}

int			main(int argc, char **argv)
{
	t_number	*stack;
	t_number	*stack2;
	t_opt		*opt;

	stack = 0;
	stack2 = 0;
	if (!create_opt(&opt) || argc == 1)
		return (1);
	while (argc-- > 1)
		if (!create_stack(&stack, *(++argv), opt))
			return (1);
	if (!read_instructions(&stack, &stack2, opt))
		return (1);
	if (!check_sort(&stack) || stack2)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free_all(&stack, &stack2, opt);
	return (0);
}
