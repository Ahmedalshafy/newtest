/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:48:35 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/19 10:42:29 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int				num;
	struct t_stack	*next;
	struct t_stack	*prev;
}					t_stack;

typedef struct t_info
{
	int				min_ind;
	int				*array;
	int				l;
}					t_info;

void				exit_error(void);
void				free_array(char **arr);
char				**ps_parsing(int ac, char *av[]);
int					ps_check_empty(char *str);
void				ps_init_ps(t_stack **stack_a);
char				*ps_join(int ac, char *av[]);
int					ps_strlen(char *str);
char				*ps_strdup(char *src);
char				*ps_strjoin(char *s1, char *s2);
void				ps_cpy_char(char s1, char s2, char *dest, int *j);
int					ps_validate(char *str);
t_stack				*ps_stack(char **av);
t_stack				*ps_stack_first(char *str);
void				ps_free_stack(t_stack *stack);
void				add_to_stack(t_stack *stack, int num);
int					ps_check_dup(t_stack *stack);
int					ft_strcmp(char *s1, char *s2);
int					ps_check_0(char *str);
void				ps_push(t_stack **stack1, t_stack **stack2);
void				pa(t_stack **stack_a, t_stack **stack_b, int print);
void				pb(t_stack **stack_a, t_stack **stack_b, int print);
void				ps_swap(t_stack **stack);
void				ss(t_stack **stack_a, t_stack **stack_b, int print);
void				sa(t_stack **stack_a, int print);
void				sb(t_stack **stack_b, int print);
void				ps_rotate(t_stack **stack);
void				ra(t_stack **stack_a, int print);
void				rb(t_stack **stack_b, int print);
void				rr(t_stack **stack_a, t_stack **stack_b, int print);
void				ps_rev_rotate(t_stack **stack);
void				rra(t_stack **stack_a, int print);
void				rrb(t_stack **stack_b, int print);
void				rrr(t_stack **stack_a, t_stack **stack_b, int print);
t_stack				*ps_stack_last(t_stack *stack);
int					stack_len(t_stack *stack);
int					ps_is_sorted(t_stack *stack);
int					ps_is_rev_sorted(t_stack *stack);
void				ps_sort_three(t_stack **stack);
int					*ps_put_in_arr(t_stack *stack);
void				ps_quick_sort(int *array, int start, int n);
void				ps_max_chunck(t_stack **stack_a, t_stack **stack_b,
						t_info info, int size);
void				ps_rot_a(t_stack **stack_a, t_stack **stack_b,
						t_info info, int size);
void				ps_rot_a_size(t_stack **stack_a, t_stack **stack_b,
						t_info info, int size);
void				ps_rev_rot_a(t_stack **stack_a, t_stack **stack_b,
						int min_value, int size);
void				ps_rev_rot_a_size(t_stack **stack_a, t_stack **stack_b,
						int min_value, int size);
void				ps_rot_b(t_stack **stack_a, t_stack **stack_b,
						int min_value, int size);
void				ps_rev_rot_b(t_stack **stack_a, t_stack **stack_b,
						int min_value, int size);
void				ps_sec_chunck(t_stack **stack_a, t_stack **stack_b,
						t_info info, int size);
void				ps_thrd_chunck(t_stack **stack_a, t_stack **stack_b,
						t_info info, int size);
void				ps_sort_three_last_a(t_stack **stack_a, t_stack **stack_b);
void				ps_sort_three_a(t_stack **stack_a, t_stack **stack_b);
void				ps_rev_rot_sort_3_a(t_stack **stack_a, t_stack **stack_b,
						int size);
void				ps_sort_three_last_b(t_stack **stack_a, t_stack **stack_b);
void				ps_sort_top_3_b(t_stack **stack_a, t_stack **stack_b);
void				ps_push_bottom_3_b(t_stack **stack_a, t_stack **stack_b);
void				ps_push_top_b(t_stack **stack_a, t_stack **stack_b,
						t_info info, int size);
void				ps_push_three_a(t_stack **stack_a, t_stack **stack_b,
						int push_count);
void				ps_push_top_less_3_b(t_stack **stack_a, t_stack **stack_b,
						int size);
void				ps_push_bottom_b(t_stack **stack_a, t_stack **stack_b,
						int size);
void				ps_less_9(t_stack **stack_a, t_stack **stack_b,
						t_info info, int size);
void				ps_max_3(t_stack **stack_a, t_stack **stack_b,
						t_info info, int size);
void				ps_rot_a2(t_stack **stack_a, t_stack **stack_b,
						int min_value, int size);
void				ps_rev_rot_a2(t_stack **stack_a, t_stack **stack_b,
						int min_value, int size);
void				ps_rot_b2(t_stack **stack_a, t_stack **stack_b,
						int min_value, int size);
void				ps_last_cases(t_stack **stack_a, t_stack **stack_b,
						int size, int count_rb);
void				ps_rev_rot_b2(t_stack **stack_a, t_stack **stack_b,
						int min_value, int size);
void				ps_thrd_less_9(t_stack **stack_a, t_stack **stack_b,
						t_info info, int size);
int					ps_check_stack_b(t_stack **stack_b, int min_ind);
int					ps_check_stack_a(t_stack **stack_a, int min_ind);
void				ps_rot_b_size(t_stack **stack_a, t_stack **stack_b,
						int min_value, int size);
void				ps_sort_5_a(t_stack **stack_a, t_stack **stack_b);
void				ps_sort_4_a(t_stack **stack_a, t_stack **stack_b);
void				ps_push_1_to_a(t_stack **stack_a, t_stack **stack_b);
void				ps_push_2_to_a(t_stack **stack_a, t_stack **stack_b);
void				ps_init_checker(t_stack **stack_a);
void				ps_excute_ins(t_stack **stack_a, t_stack **stack_b,
						char *line);
void				ps_read(t_stack **stack_a);
t_info				ps_edit_info(t_info info, int size, int l);
void				ps_init_info(t_info *info, int *array);
void				ps_ss_condition(t_stack **stack_a, t_stack **stack_b);
void				ps_sort_last_3_a2(t_stack **stack_a, t_stack **stack_b);
int					ps_partition(int *array, int start, int n);
void				ps_excute_ins_2(t_stack **stack_a, t_stack **stack_b,
						char *line);

#endif
