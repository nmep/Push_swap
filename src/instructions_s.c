/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:27:38 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/14 19:48:22 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_list(t_list **lst)
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

void	sa(t_list **stack_a)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	s_list(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	if (!(*sb) || !(*stack_b)->next)
		return ;
	s_list(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	s_list(stack_a);
	s_list(stack_b);
	write(1, "ss\n", 3);
}
