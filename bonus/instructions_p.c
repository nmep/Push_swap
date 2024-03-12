/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:10:01 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/15 10:38:12 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	p_b_list(t_list **lst1, t_list **lst2)
{
	t_list (*tmp) = *lst1;
	if (!(*lst2))
	{
		(*lst2) = tmp;
		(*lst1) = tmp->next;
		tmp->next->prev = NULL;
		tmp->next = NULL;
		return ;
	}
	(*lst1) = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	tmp->next = (*lst2);
	(*lst2)->prev = tmp;
	(*lst2) = tmp;
	init_index_list(lst1);
}

void	pa_b(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b))
		return ;
	p_b_list(stack_b, stack_a);
	init_index_list(stack_a);
}

void	pb_b(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_a))
		return ;
	p_b_list(stack_a, stack_b);
	init_index_list(stack_b);
}
