/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:30:11 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 11:53:55 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_number		*stack_create_node(int num)
{
	t_number	*node;

	node = (t_number*)malloc(sizeof(t_number));
	if (!node)
		return (0);
	node->num = num;
	node->next = 0;
	node->prev = 0;
	return (node);
}

int					stack_push_back(t_number **head, int num)
{
	t_number	*new;
	t_number	*temp;

	new = stack_create_node(num);
	if (!new || !head)
		return (0);
	if (!(*head))
		*head = new;
	else
	{
		temp = *head;
		while (temp && temp->next != *head)
		{
			if (temp->num == num)
			{
				free(new);
				return (0);
			}
			temp = temp->next;
		}
		if (temp && temp->num == num)
			return (0);
		push_behind(head, new);
	}
	return (1);
}

int					push(t_number **head, t_number *num)
{
	t_number	*temp;

	temp = 0;
	if (!head)
		return (0);
	if (*head)
	{
		num->next = *head;
		temp = (*head)->prev;
		(*head)->prev = num;
	}
	if (temp)
	{
		temp->next = num;
		num->prev = temp;
	}
	else if (!temp && *head)
	{
		(*head)->next = num;
		num->prev = *head;
	}
	*head = num;
	return (1);
}

int					push_behind(t_number **head, t_number *num)
{
	t_number	*temp;

	temp = 0;
	if (!head)
		return (0);
	if (*head)
	{
		num->next = *head;
		temp = (*head)->prev;
		(*head)->prev = num;
	}
	if (temp)
	{
		temp->next = num;
		num->prev = temp;
	}
	else if (!temp && *head)
	{
		(*head)->next = num;
		num->prev = *head;
	}
	return (1);
}

t_number			*pop(t_number **head)
{
	t_number	*node;

	if (!head || !(*head))
		return (0);
	node = *head;
	*head = (*head)->next;
	if (*head && node->prev == *head)
	{
		(*head)->prev = 0;
		(*head)->next = 0;
	}
	else if (*head && node->prev != *head)
	{
		(*head)->prev = node->prev;
		node->prev->next = *head;
	}
	node->next = 0;
	node->prev = 0;
	return (node);
}
