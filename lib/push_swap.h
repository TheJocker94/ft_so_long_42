/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:14:35 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/01 21:14:38 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../src/libft.h"

typedef struct t_stack
{
	int				val;
	int				group;
	int				order;
	struct t_stack	*next;
}					t_stack;
/*Creation and manipulation list*/
void				display_list(t_stack *start);
void				display_group(t_stack *start);
t_stack				*create_node(int val);
void				release(t_stack *start);
void				reverse_list(t_stack **stnode);
void				addtop(t_stack **start, int new, int group);
void				addbot(t_stack **start, int new);
int					lst_size(t_stack *start);
t_stack				*create_list(int ac, char **av);
void				sw_a(t_stack **start, int j);
void				sw_b(t_stack **start, int j);
void				ss(t_stack **a, t_stack **b, int j);
void				push_b(t_stack **stack_a, t_stack **stack_b, int j);
void				push_a(t_stack **stack_a, t_stack **stack_b, int j);
t_stack				*lst_last(t_stack *start);
void				rot_a(t_stack **stack_a, int j);
void				rot_base(t_stack **stack_a);
void				rr_a(t_stack **stack_a, int j);
void				rot_b(t_stack **stack_a, int j);
void				rr(t_stack **a, t_stack **b, int j);
void				rr_base(t_stack **stack_a);
void				rr_b(t_stack **stack_a, int j);
void				rrr(t_stack **a, t_stack **b, int j);
int					medium_val(t_stack *list);
long				ft_atol(char *str);
int					ft_strdigit(char *str);
int					is_int(char *str);
int					check_double(int i, int j, int ac, char **av);
int					check_args(int ac, char **av);
int					check_order_little(t_stack **list, int size);
void				ft_sort_2(t_stack **a);
void				ft_sort_3(t_stack **a);
void				first_sort_3_if(t_stack *tmp, t_stack *tmp2, t_stack *tmp3,
						t_stack **a);
void				sort_logic(t_stack ***stack_a, t_stack ***stack_b, int div);
void				ft_sort_5(t_stack **a, t_stack **b, int size);
int					is_min(t_stack *a);
int					is_max(t_stack *a);
int					find_min_pos(t_stack *a);
int					is_group(t_stack *a, int id);
void				push_min(t_stack **a, t_stack **b);
int					find_inter(t_stack *a);
int					pos_group_top(t_stack *a, int id);
int					pos_group_bot(t_stack *a, int id);
void				push_top(t_stack **a, t_stack **b, int pos);
void				push_bot(t_stack **a, t_stack **b, int pos, int list_size);
void				push_group(t_stack **a, t_stack **b, int id);
int					find_max_pos(t_stack *a);
void				push_max(t_stack **a, t_stack **b, int max);
void				sort_big(t_stack **stack_a, t_stack **stack_b, int div);
void				push_ordered(t_stack **b, int min);
void				is_newmin(t_stack *a, int order, int group);
int					is_ordered(t_stack *a);
void				init_min(t_stack *a);
int					is_min_group(t_stack *a, int div);
void				groupon(t_stack **a, int size, int div);
int					find_max_min_pos(t_stack *a, int div);
int					is_max_group(t_stack *a, int div);
void				display_order(t_stack *start);
int					push_group_back(t_stack **a, t_stack **b, int min, int max);
int					is_next_top(t_stack **a, int id);
void				push_group_2(t_stack **a, t_stack **b, int min, int max);
void				push_bot_last(t_stack **a, t_stack **b, int pos, int max);
void				push_top_last(t_stack **a, t_stack **b, int pos, int max);
int					pos_max_min_top(t_stack *a, int min, int max);
int					pos_max_min_bot(t_stack *a, int min, int max);
int					divine(int size);
void				ft_display_exit(void);
#endif
