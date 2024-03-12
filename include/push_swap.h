/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:00:47 by garfi             #+#    #+#             */
/*   Updated: 2023/12/16 14:04:42 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define TRUE 1

# define FALSE 0

// liste

typedef struct s_list
{
	int				val;
	int				index;
	int				push_price;
	int				min;
	int				max;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// parsing

long long int	ft_atoi(char *str);
char			**split(char *str, int *size_tab);
char			*dup_word(char *str, int start, int end);
int				*str_to_int_str(char **arg, int *size_tab);
int				*str_to_int_av(char **arg, int *size_tab);
int				count_word(char *str);
int				str_to_int_str3(char **tab_char, int *tab, int *size_tab);
int				str_to_int_str2(char **arg, int *size_tab, \
	int	**tab, char ***tab_char);
int				str_to_int_av3(int *tab, int *size_tab);

// tools

int				ft_strlen(char *str);
int				check_sign(char *str);
int				check_s_nbr(char *str);
int				is_int(long long int nb);
int				ft_strcmp(char *s1, char *s2);
int				check_double(int *tab, int *size_tab);
int				check_other_char2(char *str);
int				check_other_char(char **arg);
int				check_signe_only2(char *str);
int				check_signe_only(char **arg);
int				len_tab_tab(char **str);
void			ft_free(char **tab);

// linked list

t_list			*create_list_a(int *tab, int *size);
void			init_index_list(t_list **lst);
void			dealloc_list(t_list **lst);
t_list			*find_highest(t_list **a);
int				stack_sorted(t_list **lst, int *len, char **av, int ac);
t_list			*str_tab_to_list(char **av, int *len, int ac);
void			litle_sort(t_list **a);
int				lst_size(t_list **lst);

// rotate
void			r_list(t_list **lst);
void			ra(t_list **stack_a);
void			rb(t_list **stack_b);
void			rr(t_list **stack_a, t_list **stack_b);

// reverse rotate
void			rr_list(t_list **stack_a);
void			rra(t_list **stack_a);
void			rrb(t_list **stack_a);
void			rrr(t_list **stack_a, t_list **stack_b);

// swap
void			s_list(t_list **lst);
void			sa(t_list **stack_a);
void			sb(t_list **stack_b);
void			ss(t_list **stack_a, t_list **stack_b);

// push

void			p_list(t_list **lst1, t_list **lst2);
void			pa(t_list **stack_a, t_list **stack_b);
void			pb(t_list **stack_a, t_list **stack_b);

// algo

void			init_push_price(t_list *a, t_list *b);
void			init_target_node(t_list **a, t_list **b);
void			init_target_and_price(t_list **a, t_list **b);
t_list			*smallest_bigger(t_list **b, t_list *node);
t_list			*bigger_smallest(t_list **b, t_list *node);
t_list			*smallest(t_list **lst);
void			algo(t_list **a, t_list **b);
void			pushing_to_b(t_list **a, t_list **b);
void			pushing_to_a(t_list **a, t_list **b);
void			pushing_b(t_list **a, t_list **b, t_list *node);
void			pushing_a(t_list **a, t_list **b, t_list *node);
t_list			*bigger(t_list **b);
t_list			*find_cheapest(t_list **a);
void			init_target_node_b(t_list **a, t_list **b);
void			sort_5(t_list **a, t_list **b);
void			init_target_and_price_b(t_list **a, t_list **b);
// void	init_push_price_b(t_list *a, t_list *b);
void			finaly_order(t_list **a);

#endif
