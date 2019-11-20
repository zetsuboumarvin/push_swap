/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:33:23 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/20 14:36:23 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define CHUNK_SIZE 4

typedef struct		s_number
{
	int				num;
	struct s_number	*next;
	struct s_number	*prev;
}					t_number;

typedef struct		s_opt
{
	int				help;
	int				display;
	int				color;
	int				file;
	int				fd;
	int				st;
	int				count;
	int				direct;
	int				read_file;
	char			*file_name;
}					t_opt;

int					create_stack(t_number **stack, char *s, t_opt *opt);
int					parse_string(char *s, int *num, t_opt *opt);
int					free_error(t_number **stack, t_number **stack2,
								int result, t_opt *opt);
void				free_stack(t_number **head);
int					stack_push_back(t_number **head, int num);

int					push(t_number **head, t_number *num);
t_number			*pop(t_number **head);
int					swap(t_number **stack);
int					push_from_to(t_number **consumer, t_number **producer);
int					rotate(t_number **stack);
int					push_behind(t_number **head, t_number *num);
int					rev_rotate(t_number **stack);

int					check_sort(t_number **head);

void				dsort2(t_number **stack, t_number **stack2, t_opt *opt);
void				dsort3(t_number **stack, t_number **stack2, t_opt *opt);

void				count_swap(t_number **stack, int count, int st, t_opt *opt);
void				count_rotate(t_number **stack, int count,
								int st, t_opt *opt);
void				count_rev_rotate(t_number **stack, int count,
								int st, t_opt *opt);
void				count_push(t_number **cons, t_number **prod, t_opt *opt);

int					find_min_way(t_number **stack, int num, int *count);
void				find_min(t_number **stack, int *tmin);
int					count_length(t_number **stack);
void				do_reverse_a(t_number **stack, t_number **stack2,
									t_opt *opt);
void				do_reverse_b(t_number **stack, t_number **stack2,
									t_opt *opt);
int					get_last(t_number **stack);

int					get_medium(t_number **stack, int last);
void				q_sort(t_number **stack, t_number **stack2, t_opt *opt);
int					find_and_push(t_number **stack, t_number **stack2,
									int med, t_opt *opt);
void				q_sort_b(t_number **stack, t_number **stack2, t_opt *opt);
int					do_correct_reverse(t_number **stack, t_number **stack2,
										int med, t_opt *opt);
int					find_nums(t_number **stack, int *num1, int *num2, int med);
int					find_min_way_a(t_number **stack, int num, int *count);

int					create_opt(t_opt **opt);
void				display_stacks(t_number **stack, t_number **stack2);
void				display_stacks_color(t_number **stack, t_number **stack2,
											int color);
int					parse_options(t_opt *opt, char *s);
void				do_sort_b(t_number **stack, t_number **stack2, t_opt *opt,
											int chunk);
int					free_string_arr(char **s, char *test);
int					init_sort_a(t_number **stack, t_number **stack2, int n,
											t_opt *opt);
int					free_node(t_number *new);

#endif
