/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:33:46 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 12:00:04 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				create_opt(t_opt **opt)
{
	*opt = (t_opt*)malloc(sizeof(t_opt));
	if (!*opt)
		return (0);
	(*opt)->help = 0;
	(*opt)->color = 0;
	(*opt)->display = 0;
	(*opt)->file = 0;
	(*opt)->fd = 1;
	(*opt)->read_file = 0;
	(*opt)->file_name = 0;
	return (1);
}

int				free_string_arr(char **s, char *test)
{
	char	**start;
	id_t	i;

	start = s;
	i = 0;
	while (s && s[i])
		free(s[i++]);
	if (start)
		free(start);
	if (test && *test)
		free(test);
	return (-1);
}

static int		do_opt(t_opt *opt, char *s)
{
	if (parse_options(opt, s) && !(opt->help))
		return (1);
	else if (parse_options(opt, s) && opt->help)
	{
		ft_putstr("Usage: ./push_swap ARGS | ./checker ARGS\nor\n");
		ft_putstr("./push_swap ARGS\nor\n");
		ft_putstr("./checker ARGS and then insert commands\n");
		ft_putstr("Flags: -c - color, -v - visual mode, f - write in file\n");
		ft_putstr("[checker: -Fname_file - read instructions from file\n");
		return (0);
	}
	return (0);
}

int				parse_string(char *s, int *num, t_opt *opt)
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
		if (do_opt(opt, string[i++]))
			continue ;
		temp = (long int)ft_atoi(string[--i]);
		test = ft_itoa(temp);
		if (!ft_strcmp(test, string[i++]))
			num[j++] = temp;
		else
			return (free_string_arr(string, test));
		free(test);
	}
	free_string_arr(string, 0);
	return (j);
}
