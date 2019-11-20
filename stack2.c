/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:34:04 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 16:12:06 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				free_error(t_number **stack, t_number **stack2,
							int result, t_opt *opt)
{
	free_stack(stack);
	free_stack(stack2);
	if (opt)
		free(opt);
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
		return (free_error(stack, 0, 0, opt));
	while (n-- > 0)
		if (!stack_push_back(stack, num[i++]))
			return (free_error(stack, 0, 0, opt));
	return (1);
}
