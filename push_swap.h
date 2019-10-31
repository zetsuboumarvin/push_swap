/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:33:23 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/31 14:54:11 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

typedef struct		s_number
{
	int				num;
	struct s_number	*next;
}					t_number;


int					push_back(t_number **head, int num);
int					push(t_number **head, t_number *num);
t_number			*pop(t_number **head);
