/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:30:11 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/31 14:53:25 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_number		*create_node(int num)
{
	t_number	*node;

	node = (t_number*)malloc(sizeof(t_number));
	if (!node)
		return (0);
	node->num = num;
	node->next = 0;
	return (node);
}

int					push_back(t_number **head, int num)
{
	t_number	*new;
	t_number	*temp;

	temp = *head;
	new = create_node(num);
	if (!new || !head)
		return (0);
	if (!(*head))
		*head = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}

int					push(t_number **head, t_number *num)
{
	if (!head)
		return (0);
	num->next = *head;
	*head = num;
	return (1);
}

t_number			*pop(t_number **head)
{
	t_number	*node;

	if (!head || !(*head))
		return (0);
	node = *head;
	*head = (*head)->next;
	return (node);
}
