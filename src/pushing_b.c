/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:01:01 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/14 20:03:26 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pushing_b2(t_list **a, t_list **b, t_list *node)
{
	while (node->prev != NULL)
		rra(a);
	while (node->target->prev != NULL)
		rb(b);
}

void	pushing_b1(t_list **a, t_list **b, int *m_b, t_list *node)
{
	int	m_a;

	m_a = lst_size(a) / 2;
	if (node->index <= m_a && node->target->index >= *m_b)
	{
		while (node->prev != NULL)
			ra(a);
		while (node->target->prev != NULL)
			rrb(b);
	}
	else if (node->index >= m_a && node->target->index >= *m_b)
	{
		while (node->prev != NULL && node->target->prev != NULL)
			rrr(a, b);
		while (node->prev != NULL)
			rra(a);
		while (node->target->prev != NULL)
			rrb(b);
	}
	else if (node->index >= m_a && node->target->index <= *m_b)
		pushing_b2(a, b, node);
}

void	pushing_b(t_list **a, t_list **b, t_list *node)
{
	int	median_a;
	int	median_b;

	median_a = lst_size(a) / 2;
	median_b = lst_size(b) / 2;
	if ((node->index <= median_a && node->target->index >= median_b)
		|| (node->index >= median_a && node->target->index >= median_b)
		|| (node->index >= median_a && node->target->index <= median_b))
		pushing_b1(a, b, &median_b, node);
	else
	{
		while (node->prev != NULL && node->target->prev != NULL)
			rr(a, b);
		while (node->prev != NULL)
			ra(a);
		while (node->target->prev != NULL)
			rb(b);
	}
	pb(a, b);
}

// void	pushing_b(t_list **a, t_list **b, t_list *node)
// {
// 	int	median_a;
// 	int	median_b;

// 	median_a = lst_size(a) / 2;
// 	median_b = lst_size(b) / 2;
// 	if (node->index <= median_a && node->target->index >= median_b)
// 	{
// 		while (node->prev != NULL)
// 			ra(a);
// 		while (node->target->prev != NULL)
// 			rrb(b);
// 	}
// 	else if (node->index >= median_a && node->target->index >= median_b)
// 	{
// 		while (node->prev != NULL && node->target->prev != NULL)
// 			rrr(a, b);
// 		while (node->prev != NULL)
// 			rra(a);
// 		while (node->target->prev != NULL)
// 			rrb(b);
// 	}
// 	else if (node->index >= median_a && node->target->index <= median_b)
// 	{
// 		while (node->prev != NULL)
// 			rra(a);
// 		while (node->target->prev != NULL)
// 			rb(b);
// 	}
// 	else
// 	{
// 		while (node->prev != NULL && node->target->prev != NULL)
// 			rr(a, b);
// 		while (node->prev != NULL)
// 			ra(a);
// 		while (node->target->prev != NULL)
// 			rb(b);
// 	}
// 	pb(a, b);
// }

void	pushing_to_b(t_list **a, t_list **b)
{
	t_list	*node_to_push;
	int		len_a;

	len_a = lst_size(a);
	while (len_a > 5)
	{
		init_target_and_price(a, b);
		node_to_push = find_cheapest(a);
		pushing_b(a, b, node_to_push);
		len_a--;
	}
}
