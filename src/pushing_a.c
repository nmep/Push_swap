/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:00:06 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/14 19:58:58 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pushing_a2(t_list **a, t_list **b, t_list *node, int *median_a)
{
	int	median_b;

	median_b = lst_size(b) / 2;
	if (node->index <= median_b && node->target->index >= *median_a)
	{
		while (node->prev != NULL)
			rb(b);
		while (node->target->prev != NULL)
			rra(a);
	}
	else if (node->index >= median_b && node->target->index >= *median_a)
	{
		while (node->prev != NULL && node->target->prev != NULL)
			rrr(a, b);
		while (node->prev != NULL)
			rrb(b);
		while (node->target->prev != NULL)
			rra(a);
	}
}

void	pushing_a(t_list **a, t_list **b, t_list *node)
{
	int	median_a;
	int	median_b;

	median_a = lst_size(a) / 2;
	median_b = lst_size(b) / 2;
	if ((node->index <= median_b && node->target->index >= median_a)
		|| (node->index >= median_b && node->target->index >= median_a))
		pushing_a2(a, b, node, &median_a);
	else if (node->index >= median_b && node->target->index <= median_a)
	{
		while (node->prev != NULL)
			rrb(b);
		while (node->target->prev != NULL)
			ra(a);
	}
	else
	{
		while (node->prev != NULL && node->target->prev != NULL)
			rr(a, b);
		while (node->target->prev != NULL)
			ra(a);
		while (node->prev != NULL)
			rb(b);
	}
	pa(a, b);
}

void	pushing_to_a(t_list **a, t_list **b)
{
	t_list	*node_to_push;
	int		len_b;

	len_b = lst_size(b);
	while (len_b > 0)
	{
		init_target_and_price_b(a, b);
		node_to_push = find_cheapest(b);
		pushing_a(a, b, node_to_push);
		len_b--;
	}
	finaly_order(a);
}
