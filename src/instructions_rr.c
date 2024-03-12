/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:50:03 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/14 19:48:17 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rr_list(t_list **lst)
{
	t_list	*last;
	t_list	*first;

	if (!(*lst) || !(*lst)->next)
		return ;
	last = *lst;
	first = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
	last->prev->next = NULL;
	last->prev = NULL;
	first->prev = last;
	(*lst) = last;
	init_index_list(lst);
}

void	rra(t_list **stack_a)
{
	rr_list(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_a)
{
	rr_list(stack_a);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rr_list(stack_a);
	rr_list(stack_b);
	write(1, "rrr\n", 4);
}
