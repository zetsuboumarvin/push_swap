/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:54:41 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/31 15:06:34 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static		int create_stack(char *s)
{
	int			num;
	t_number	*stack;

	stack = 0;
	num = 0;
	if (!parse_string(s, &num))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!push_back(&stack, num))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
}

int			main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	while (argc-- > 1)
	{
		++argv;
		if (!create_stack(*argv))
			return (1);
	}
}
