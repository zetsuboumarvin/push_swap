/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:33:23 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/15 11:10:36 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
# define CHUNK_SIZE 4

typedef struct		s_number
{
	int				num;
	struct s_number	*next;
	struct s_number	*prev;
}					t_number;

typedef struct		s_sort
{
	int				mid;
	int				start;
	int				end;
}					t_sort;

int					create_stack(t_number **stack, char *s);
int					parse_string(char *s, int *num);
int					free_error(t_number **stack, t_number **stack2, int result);
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

void				dsort2(t_number **stack, int first);
void				dsort3(t_number **stack, int first);
void				argc5(t_number **stack, t_number **stack2);
void				argc6(t_number **stack, t_number **stack2);
void				argc7(t_number **stack, t_number **stack2);

void				double_rotate(t_number **stack, t_number **stack2, int count);
void				double_rev_rotate(t_number **stack, t_number **stack2, int count);
void				double_swap(t_number **stack, t_number **stack2, int count);
void				count_swap(t_number **stack, int count, int st);
void				count_rotate(t_number **stack, int count, int st);
void				count_rev_rotate(t_number **stack, int count, int st);
void				count_push(t_number **cons, t_number **prod, int count, int st);

int					find_min_way(t_number **stack, int num, int *count);
void				find_min(t_number **stack, int *tmin);
void				find_max(t_number **stack, int *tmax);
int					count_length(t_number **stack);
void				do_reverse_a(t_number **stack, int direct, int count, int print);
void				do_reverse_b(t_number **stack, int direct, int count, int print);
void				do_reverse_d(t_number **stack, t_number **stack2, int direct, int count);
int					get_last(t_number **stack);

int					get_medium(t_number **stack, int last);
void				merge(t_number **stack, t_number **stack2);
int					count_length_in(t_number **stack, int start, int end);
void				min_sort(t_number **stack, t_sort data, int first);
int					q_sort(t_number **stack, t_number **stack2);
void				a_sort2(t_number **stack, int st);
void				a_sort3(t_number **stack, int st);
void				a_sort4(t_number **stack);
void				a_dsort4(t_number **stack);
void				b_sort2(t_number **stack, int st);
void				b_sort3(t_number **stack, int st);
void				b_dsort3(t_number **stack);
void				b_dsort4(t_number **stack);
int					find_and_push(t_number **stack, t_number **stack2, int med, int st);
void				do_reverse_b(t_number **stack, int direct, int count, int print);
int					check_sort_rev(t_number **head);
void				q_sort_b(t_number **stack, t_number **stack2);
