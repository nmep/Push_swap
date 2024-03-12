/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:41:44 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/15 20:37:11 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	r_list(t_list **lst)
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

void	ra(t_list **stack_a)
{
	if (!(*stack_a))
		return ;
	r_list(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	if (!*(stack_b))
		return ;
	r_list(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	r_list(stack_a);
	r_list(stack_b);
	write (1, "rr\n", 3);
}
