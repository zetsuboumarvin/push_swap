/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:29:34 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 10:40:30 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_opt(t_opt *opt, char *s)
{
	int			i;

	if (ft_strchr(s, 'h') && !ft_strchr(s, 'F'))
		opt->help = 1;
	if (ft_strchr(s, 'v') && !ft_strchr(s, 'F'))
		opt->display = 1;
	if (ft_strchr(s, 'c') && !ft_strchr(s, 'F'))
		opt->color = 1;
	if (ft_strchr(s, 'F'))
	{
		i = 0;
		while (s[i] != ' ' && s[i])
			i++;
		opt->file_name = ft_strsub(s, 2, i - 2);
		opt->read_file = 1;
	}
}

int			parse_options(t_opt *opt, char *s)
{
	int		fd;

	if (s[0] != '-')
		return (0);
	if (ft_strchr(s, 'f') && !ft_strchr(s, 'F'))
	{
		opt->file = 1;
		fd = open("push_swap_commands.txt", O_RDWR | O_CREAT | O_TRUNC,
					S_IRWXU | S_IRWXG | S_IRWXO);
		if (fd <= 0)
			return (0);
		opt->fd = fd;
	}
	check_opt(opt, s);
	if (opt->help || opt->display || opt->color || opt->file || opt->read_file)
		return (1);
	return (0);
}

void		display_stacks(t_number **stack, t_number **stack2)
{
	t_number	*top_a;
	t_number	*top_b;

	top_a = *stack;
	top_b = *stack2;
	ft_printf("    A        B    \n");
	while (top_a || top_b)
	{
		if (top_a && top_b)
			ft_printf("%-9d%-9d\n", top_a->num, top_b->num);
		else if (top_a)
			ft_printf("%-9d\n", top_a->num);
		else if (top_b)
			ft_printf("         %-9d\n", top_b->num);
		if (top_a && top_a->next && top_a->next != *stack)
			top_a = top_a->next;
		else
			top_a = 0;
		if (top_b && top_b->next && top_b->next != *stack2)
			top_b = top_b->next;
		else
			top_b = 0;
	}
	ft_printf("------------------\n\n");
}

static char	*get_col(int color)
{
	if (color == 0)
		return (ANSI_COLOR_MAGENTA);
	else if (color == 1)
		return (ANSI_COLOR_RED);
	else if (color == 2)
		return (ANSI_COLOR_YELLOW);
	else
		return (ANSI_COLOR_GREEN);
}

void		display_stacks_color(t_number **stack, t_number **st2, int color)
{
	t_number	*top_a;
	t_number	*top_b;
	char		*col;

	top_a = *stack;
	top_b = *st2;
	col = get_col(color);
	ft_printf("%s    A        B    {eoc}\n", col);
	while (top_a || top_b)
	{
		if (top_a && top_b)
			ft_printf("%s%-9d%-9d{eoc}\n", col, top_a->num, top_b->num);
		else if (top_a)
			ft_printf("%s%-9d{eoc}\n", col, top_a->num);
		else if (top_b)
			ft_printf("%s         %-9d{eoc}\n", col, top_b->num);
		top_a = top_a && top_a->next && top_a->next != *stack ? top_a->next : 0;
		top_b = top_b && top_b->next && top_b->next != *st2 ? top_b->next : 0;
	}
	ft_printf("%s------------------{eoc}\n\n", col);
}
