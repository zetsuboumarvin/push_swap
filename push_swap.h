/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:33:23 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/04 18:26:17 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_number
{
	int				num;
	struct s_number	*next;
}					t_number;


int					stack_push_back(t_number **head, int num);
int					push(t_number **head, t_number *num);
t_number			*pop(t_number **head);
int					parse_string(char *s, int *num);
void				free_stack(t_number **head);
int					free_error(t_number **stack, t_number **stack2, int result);
int					swap(t_number **stack);
int					push_from_to(t_number **consumer, t_number **producer);
int					rotate(t_number **stack);
int					push_behind(t_number **head, t_number *num);
int					rev_rotate(t_number **stack);
int					check_sort(t_number **head);
