/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:34:04 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 10:37:36 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				free_error(t_number **stack, t_number **stack2, int result)
{
	free_stack(stack);
	free_stack(stack2);
	ft_putstr_fd("Error\n", 2);
	return (result);
}

void			free_stack(t_number **head)
{
	t_number		*temp;

	if (head)
	{
		if (*head && (*head)->prev)
			(*head)->prev->next = 0;
		while (*head)
		{
			temp = (*head)->next;
			free(*head);
			*head = temp;
		}
	}
}

int				check_sort(t_number **head)
{
	t_number	*temp;

	if (head)
	{
		temp = *head;
		if (!(*head) || !(temp->next))
			return (1);
		while (temp->next && temp->next != *head)
		{
			if (temp->num > temp->next->num)
				return (0);
			temp = temp->next;
		}
		return (1);
	}
	return (0);
}

int				create_stack(t_number **stack, char *s, t_opt *opt)
{
	int				num[1000];
	int				n;
	int				i;

	i = 0;
	if ((n = parse_string(s, num, opt)) == -1)
		return (free_error(stack, 0, 0));
	while (n-- > 0)
		if (!stack_push_back(stack, num[i++]))
			return (free_error(stack, 0, 0));
	return (1);
}

void			a_sort2(t_number **stack, t_number **stack2, t_opt *opt)
{
	t_number		*top;

	top = *stack;
	if (top->num > top->next->num)
	{
		swap(stack);
		ft_putstr_fd("sa\n", opt->fd);
		if (opt->display)
			display_stacks(stack, stack2);
	}
}
