/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:27:38 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/15 10:41:42 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_b_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*after;

	if (!(*lst) || !((*lst)->next))
		return ;
	tmp = *lst;
	after = tmp->next;
	after->prev = tmp->prev;
	if (after->next != NULL)
		after->next->prev = tmp;
	tmp->next = after->next;
	after->next = tmp;
	tmp->prev = after;
	*lst = after;
	init_index_list(lst);
}

void	sa_b(t_list **stack_a)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	s_b_list(stack_a);
}

void	sb_b(t_list **stack_b)
{
	if (!(*sb) || !(*stack_b)->next)
		return ;
	s_b_list(stack_b);
}

void	ss_b(t_list **stack_a, t_list **stack_b)
{
	s_b_list(stack_a);
	s_b_list(stack_b);
}
