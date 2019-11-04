/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:33:46 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/04 14:11:08 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			parse_string(char *s, int *num)
{
	long int		temp;
	char			*string;

	if (s == 0)
		return (0);
	temp = (long int)ft_atoi(s);
	string = ft_itoa(temp);
	if (!ft_strcmp(s, string))
	{
		free(string);
		*num = temp;
		return (1);
	}
	else
	{
		free(string);
		return (0);
	}
}
