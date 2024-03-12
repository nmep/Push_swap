/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:41:44 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/15 20:39:38 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	r_b_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*first;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = *lst;
	first = *lst;
	*lst = first->next;
	while (tmp->next)
		tmp = tmp->next;
	(*lst) = first->next;
	first->next->prev = NULL;
	first->next = NULL;
	first->prev = tmp;
	tmp->next = first;
	init_index_list(lst);
}

void	ra_b(t_list **stack_a)
{
	if (!(*stack_a))
		return ;
	r_b_list(stack_a);
}

void	rb_b(t_list **stack_b)
{
	if (!*(stack_b))
		return ;
	r_b_list(stack_b);
}

void	rr_b(t_list **stack_a, t_list **stack_b)
{
	r_b_list(stack_a);
	r_b_list(stack_b);
}
