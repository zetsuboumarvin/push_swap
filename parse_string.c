/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:33:46 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/19 14:19:09 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		free_string_arr(char **s, char *test)
{
	while (*s)
		free(*s++);
	free(test);
	return (0);
}

int				parse_string(char *s, int *num)
{
	long int		temp;
	char			**string;
	int				i;
	char			*test;
	int				j;

	if (s == 0)
		return (0);
	string = ft_strsplit(s, ' ');
	i = 0;
	j = 0;
	while (string[i])
	{
		temp = (long int)ft_atoi(string[i]);
		test = ft_itoa(temp);
		if (!ft_strcmp(test, string[i++]))
		{
			free(test);
			num[j++] = temp;
		}
		else
			return (free_string_arr(string, test));
	}
	return (j);
}
